#ifdef HAVE_MNTENT_H
#include <mntent.h>
#else

#ifndef mntent_h_
#define mntent_h_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/param.h>
#include <sys/ucred.h>
#include <sys/mount.h>

#define MOUNTED "mounted"
#define MNTTYPE_NFS "nfs"

//#define MOPTSLEN (256 - (MNAMELEN * 2 + MFSNAMELEN + 2 * sizeof(int)))

struct mntent {
	char *mnt_fsname;   /* file system name */
	char *mnt_dir; /* file system path prefix */
	char *mnt_type;	   /* dbg, efs,	nfs */
	char *mnt_opts;	   /* ro, hide,	etc. */
	int  mnt_freq; /* dump frequency, in days */
	int  mnt_passno;	   /* pass number on parallel fsck */
};

FILE * setmntent(char * filep, char * type);
struct mntent *getmntent(FILE * filep);
//char * hasmntopt(struct mntent * mnt, char * opt);
int endmntent(FILE * filep);

#endif /* mntent_h_ */
#endif /* not HAVE_MNTENT_H */
