#include "mntent.h"
#include <sys/param.h>
//#include <sys/ucred.h>
#include <sys/mount.h>
#include <fstab.h>

struct statfs *getmntent_mntbufp;
int getmntent_mntcount = 0;
int getmntent_mntpos = 0;
char mntent_global_opts[256];
struct mntent mntent_global_mntent;

FILE * setmntent(char * filep, char * type)
{
	getmntent_mntpos = 0;
	getmntent_mntcount = getmntinfo(&getmntent_mntbufp, MNT_WAIT);
	return (FILE *)1; // dummy
}

void getmntent_addopt(char ** c, const char * s)
{
	int i = strlen(s);
        *(*c)++ = ',';
        strcpy(*c, s);
        *c += i;
}

struct mntent *getmntent(FILE * filep)
{
	char *c = mntent_global_opts+2; 
	struct fstab *fst;
	if (getmntent_mntpos >= getmntent_mntcount)
		return 0;
	if (getmntent_mntbufp[getmntent_mntpos].f_flags & MNT_RDONLY) strcpy(mntent_global_opts, "ro");
		else strcpy(mntent_global_opts, "rw");

        if (getmntent_mntbufp[getmntent_mntpos].f_flags & MNT_SYNCHRONOUS)    getmntent_addopt(&c, "sync");
        if (getmntent_mntbufp[getmntent_mntpos].f_flags & MNT_NOEXEC)         getmntent_addopt(&c, "noexec");
        if (getmntent_mntbufp[getmntent_mntpos].f_flags & MNT_NOSUID)         getmntent_addopt(&c, "nosuid");
        if (getmntent_mntbufp[getmntent_mntpos].f_flags & MNT_NODEV)          getmntent_addopt(&c, "nodev");
        if (getmntent_mntbufp[getmntent_mntpos].f_flags & MNT_UNION)          getmntent_addopt(&c, "union");
        if (getmntent_mntbufp[getmntent_mntpos].f_flags & MNT_ASYNC)          getmntent_addopt(&c, "async");
        if (getmntent_mntbufp[getmntent_mntpos].f_flags & MNT_NOATIME)        getmntent_addopt(&c, "noatime");
        if (getmntent_mntbufp[getmntent_mntpos].f_flags & MNT_NOCLUSTERR)     getmntent_addopt(&c, "noclusterr");
        if (getmntent_mntbufp[getmntent_mntpos].f_flags & MNT_NOCLUSTERW)     getmntent_addopt(&c, "noclusterw");
        if (getmntent_mntbufp[getmntent_mntpos].f_flags & MNT_NOSYMFOLLOW)    getmntent_addopt(&c, "nosymfollow");
        if (getmntent_mntbufp[getmntent_mntpos].f_flags & MNT_SUIDDIR)        getmntent_addopt(&c, "suiddir");
		
	mntent_global_mntent.mnt_fsname = getmntent_mntbufp[getmntent_mntpos].f_mntfromname;
	mntent_global_mntent.mnt_dir = getmntent_mntbufp[getmntent_mntpos].f_mntonname;
	mntent_global_mntent.mnt_type = getmntent_mntbufp[getmntent_mntpos].f_fstypename;
        mntent_global_mntent.mnt_opts = mntent_global_opts;
	if ((fst = getfsspec(getmntent_mntbufp[getmntent_mntpos].f_mntfromname)))
        {
        	mntent_global_mntent.mnt_freq = fst->fs_freq;
        	mntent_global_mntent.mnt_passno = fst->fs_passno;
        }
        else if ((fst = getfsfile(getmntent_mntbufp[getmntent_mntpos].f_mntonname)))
        {
        	mntent_global_mntent.mnt_freq = fst->fs_freq;
        	mntent_global_mntent.mnt_passno = fst->fs_passno;
        }
        else if (strcmp(getmntent_mntbufp[getmntent_mntpos].f_fstypename, "ufs") == 0) 
        {
                if (strcmp(getmntent_mntbufp[getmntent_mntpos].f_mntonname, "/") == 0)
                {
	        	mntent_global_mntent.mnt_freq = 1;
        		mntent_global_mntent.mnt_passno = 1;
                }
                else
                {
	        	mntent_global_mntent.mnt_freq = 2;
        		mntent_global_mntent.mnt_passno = 2;
                }
        } 
        else
        {
        	mntent_global_mntent.mnt_freq = 0;
        	mntent_global_mntent.mnt_passno = 0;
        }
        ++getmntent_mntpos;
	return & mntent_global_mntent;
}

int endmntent(FILE * filep)
{
	return 0;
}
