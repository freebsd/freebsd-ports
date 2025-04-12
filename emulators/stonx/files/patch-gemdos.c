--- gemdos.c.orig	2003-12-19 20:56:06 UTC
+++ gemdos.c
@@ -10,6 +10,7 @@
 #include <stdlib.h>
 #include <string.h>
 #include <time.h>
+#include <utime.h>
 #include <unistd.h>
 #include <ctype.h>
 #include <errno.h>
@@ -83,6 +84,9 @@ typedef struct
 {
     UL bp;
     int f,redirected;
+#if LPPIPES
+    FILE *lpp;	/* special pipe descriptor for PRN:/AUX: device handling */
+#endif
 } FINFO;
 
 #define MAXDRIVES 26
@@ -93,13 +97,24 @@ char curpath[MAXDRIVES][500];
 UL gemdos_drives = 0;
 UW curdrv=0;
 char curpath[MAXDRIVES][500];
+#if LPPIPES
+char *prnpipe = NULL;
+char *auxpipe = NULL;
+#define MAXFILES 128	/* try to conform with default GEMDOS limits */
+#define H_OFFSET 6	/* and behaviour */
+#define MAXDIRS  256	/* At least, _I_ need this */
+#else
+/* FIXME: don't no the intension of those strange values
+ * stonx used here. These parameters need further discussion.
+ * see above attempt to fix them */
 #define MAXFILES 100
 #define H_OFFSET 80 /* < 100 because of problems with PC/TC's assembler */
+#define MAXDIRS  40
+#endif
 	/* FIXME: There should be one handle-pool only!  */
 static FINFO file[MAXFILES];
 static int redirect_stdh[6][MAXFILES];
 void *act_pd;
-#define MAXDIRS 40
 
 DIR *fsdir[MAXDIRS];
 char curspath[MAXDIRS][500];
@@ -282,8 +297,9 @@ void Dsetdrv (UW drv)
 
 void Dsetdrv (UW drv)
 {
+    DBG("Dsetdrv(%c), db: 0x%x = ",'A'+drv, drive_bits);
     curdrv = drv;
-#if 0
+#if 1
     if (BIT(drv,drive_bits) == 0)
     {
 	DREG(0) = TOS_EDRIVE;
@@ -296,17 +312,20 @@ void Dsetdrv (UW drv)
 	SET_Z();
     }
 #endif
+    DBG("%d (curdrv: %d)\n", DREG(1), curdrv);
 }
 
 void Dgetdrv (void)
 {
     DREG(0) = curdrv;
+    DBG("Dgetdrv() = %d\n", curdrv);
     SET_Z();
 }
 
 void Fsetdta (UL dtaptr)
 {
     UL bp = LM_UL(act_pd);
+    DBG("Process %lx DTA = %lx\n", (long)bp, (long)dtaptr);
 #if 0
     SM_UL(MEM(bp+32),dtaptr);
     SET_Z();
@@ -333,6 +352,7 @@ void fname2unix (char *stpath, char *unixpath)
 	n++;
     }
     *unixpath=0;
+    DBG("Converted <%s> to <%s>\n", a, b);
 }
 
 static char lastpath[500];
@@ -344,6 +364,7 @@ int st2unixpath (char *stpath, char *unixpath)
     drv = (stpath[1] == ':' ? toupper(stpath[0])-'A' : curdrv);
     if (((gemdos_drives>>drv)&1) == 0)
     {
+	DBG("ERROR in st2unixpath <%s>\n", stpath);
 	*unixpath=0;
 	return 0;
     }
@@ -359,6 +380,7 @@ int st2unixpath (char *stpath, char *unixpath)
     }
     fname2unix(lastpath,path);
     sprintf(unixpath,"%s%s",root[drv],path);
+    DBG("st2unixpath(%s) = <%s>\n", stpath, unixpath);
     return 1;
 }
 
@@ -382,27 +404,50 @@ int unix2fname (char *unixname, char *stname)
 	p++;
     }
     *stname=0;
+    DBG("ufile: <%s> stfile: <%s>\n", unixname, q);
     return 1;
 }
 
 static int match (char *pat, char *name)
 {
-    if (strcmp(pat,"*.*")==0) return 1;
-    else if (strcasecmp(pat,name)==0) return 1;
+    DBG("Match(<%s>, <%s>) ", pat, name);
+    if (strcmp(pat,"*.*")==0)
+    {
+		DBG("OK\n");
+		return 1;
+    }
+    else if (strcasecmp(pat,name)==0)
+    {
+		DBG("OK\n");
+		return 1;
+    }
     else
     {
 	char *p=pat,*n=name;
 	for(;*n;)
 	{
-	    if (*p=='*') {while (*n && *n != '.') n++;p++;}
-	    else if (*p=='?' && *n) {n++;p++;}
-	    else if (*p++ != *n++) return 0;
+	    if (*p=='*') {
+			while (*n && *n != '.')
+				n++;	/* skip to extension */
+			p++;		/* step over '*' */
+		}
+	    else if (*p=='?' && *n) {
+			n++; p++;	/* single match */
+		}
+	    else if (toupper(*p++) != *n++) {
+			/* FIXME: TOS always uses uppercase letters */
+			/* does mint behave different? hpj */
+			DBG("Failed\n");
+			return 0;
+		}
 	}
 	if (*p==0)
 	{
+		DBG("OK\n");
 	    return 1;
 	}
     }
+    DBG("Failed\n");
     return 0;
 }
 
@@ -411,6 +456,7 @@ void compress_path (char *path)
     char *lastdir=NULL, lastchar=0, *d, *p=path;
     char *dirstack[MAXDIRS];
     int a=0, i;
+    DBG("Before path compression: <%s>\n", p);
     d = path;
     while (*p)
     {
@@ -441,6 +487,7 @@ void compress_path (char *path)
     }
     if (d != path && *(d-1) == '\\') d--;
     *d=0;
+    DBG("Result of path compression: %s\n", path);
 }
 
 int xopendir (char *p, int doopen)
@@ -496,7 +543,19 @@ UW date2dos (time_t t)
     return x->tm_mday|((x->tm_mon+1)<<5)|(MAX(x->tm_year-80,0)<<9);
 }
 
+time_t dos2time (UW time, UW date)
+{
+    struct tm brokentime;
 
+    brokentime.tm_sec = (time & 0x001f) << 1;
+    brokentime.tm_min = (time & 0x07e0) >> 5;
+    brokentime.tm_hour = (time & 0xf800) >> 11;
+    brokentime.tm_mday = (date & 0x001f);
+    brokentime.tm_mon = (date & 0x01e0) >> 5;
+    brokentime.tm_year = ((date & 0xfe00) >> 9) + 80;
+    return mktime(&brokentime);
+}
+
 void Fsnext (void)
 {
     UL bp;
@@ -522,6 +581,7 @@ void Fsnext (void)
     bp = LM_UL(act_pd);
     dta = (DTA *)MEM(LM_UL(MEM(bp+32)));
     attribs = LM_UB(&(dta->dta_sattrib));
+    DBG("Fsnext(%s)\n", dta->dta_pat);
 
  repeat:
     SM_UL((UL *)&(dta -> magic),EVALID);
@@ -530,6 +590,7 @@ void Fsnext (void)
 	rr = (LM_W((W *)&(dta->index)));
 	if (rr < 0) {
 	    if (rr == -1) {
+		DBG("(no more files)\n");
 		DREG(0) = TOS_ENMFIL;
 		SET_Z();
 		return;
@@ -548,6 +609,7 @@ void Fsnext (void)
 	    e = xreaddir (rr);
 	    if (e == NULL)
 	    {	
+		DBG("(no more files)\n");
 		DREG(0) = TOS_ENMFIL;
 		SET_Z();
 		xclosedir(LM_UW((UW *)&(dta->index)));
@@ -558,6 +620,7 @@ void Fsnext (void)
     SM_UL((UL *)&(dta->magic),SVALID);
     strcpy(dta->dta_name, stname);
     sprintf (uname, "%s/%s", curspath[rr], e->d_name);
+    DBG("stat(%s)\n", uname);
     if (STATFUNC (uname, &s) < 0)
 	goto repeat;
     da = (s.st_mode & S_IFDIR)?0x10:0; 	/* FIXME */
@@ -600,7 +663,7 @@ void Dsetpath (char *pname)
 	return;
     }
     if (pname[1] == ':') strcpy(pname,&pname[2]); /* for Dsetdrv(C:\FOO) */
-    if (pname[0] == '\\') strcpy(curpath[drv],pname);
+    if (!pname[0] || (pname[0] == '\\')) strcpy(curpath[drv],pname);
     else
     {
 	strcat(curpath[drv],"\\");
@@ -609,6 +672,8 @@ void Dsetpath (char *pname)
 #if 1
     compress_path(curpath[drv]);
 #endif
+    DBG("Dsetpath(%s) -> %s on drive %d <%s>\n",
+				pname, curpath[drv], curdrv, upath);
     /* FIXME */
     DREG(0)=0;
     SET_Z();
@@ -626,6 +691,7 @@ void Fsfirst (char *fspec, UW attribs)
 	cursdrv=999;
 	return;
     }
+	DBG("Fsfirst(%s,%x) on drive %d\n", fspec, attribs, curdrv);
     if (fspec[1]==':') cursdrv=toupper(fspec[0])-'A';
     else cursdrv=curdrv;
     bp = LM_UL(act_pd);
@@ -657,6 +723,7 @@ void Fsfirst (char *fspec, UW attribs)
 	!strchr (dta -> dta_pat, '*')) {
 	r = xopendir (upath, 0);
     } else {
+	DBG("Opendir(%s)\n", upath);
 	r = xopendir (upath, 1);
 	if (r < 0)
 	{
@@ -690,13 +757,17 @@ void Fopen (char *fname, UW mode)
     UL bp;
     int f;
     char upath[500];
+    struct stat s;
+
     if (!st2unixpath(fname, upath))
     {
 	DBG("Fopen(%s,%x) drive %d not done\n",fname,mode,curdrv);
+	DREG(0) = TOS_EFILNF;
+	SET_Z();
 	return;
     }
     bp = LM_UL(act_pd);
-    DBG("Fopen(%s,%x) on drive %d -> %s\n",fname,mode,curdrv,upath);
+    DBG("Fopen(\"%s\",%x) on drive %d -> %s\n",fname,mode,curdrv,upath);
     for (i=0; i<MAXFILES && file[i].bp != 0; i++)
 	if (i >= MAXFILES)
 	{
@@ -713,6 +784,13 @@ void Fopen (char *fname, UW mode)
 	SET_Z();
 	return;
     }
+    fstat(f,&s);
+    if (S_ISDIR(s.st_mode)) {
+	DBG("Fopen: %s is a directory\n",fname);
+	DREG(0) = TOS_EFILNF;
+	SET_Z();
+	return;
+    }
     file[i].bp = bp;
     file[i].f = f;
     file[i].redirected = 0;
@@ -738,6 +816,15 @@ void Fread (W handle, UL count, char *buf)
 	SET_Z();
 	return;
     }
+#if LPPIPES
+    /* ignore reading on a lppipe */
+    if (file[i].lpp)
+    {
+	DREG(0) = 0;
+	SET_Z();
+	return;
+    }
+#endif
     if (count > 0x1fffffff) count = 0x1fffffff;
     rd = FREAD_CHUNK;
     for(;count > 0;)
@@ -775,7 +862,16 @@ void Fclose (W handle)
 	SET_Z();
 	return;
     }
-    close(file[i].f);
+#if LPPIPES
+    /* close lp pipe */
+    if (file[i].lpp)
+    {
+	pclose(file[i].lpp);
+	file[i].lpp = NULL;
+    }
+    else
+#endif
+	close(file[i].f);
     file[i].bp = 0;
     file[i].f = -1;
     /* handle end of redirection (see Fforce) */
@@ -787,16 +883,66 @@ void Fcreate (char *fname, UW attribs)
 
 void Fcreate (char *fname, UW attribs)
 {
-    int i;
-    UL bp;
-    int f;
+    int i=0;
+    int f=0;
+    UL bp=LM_UL(act_pd);
     char upath[500];
+
+#if LPPIPES
+    /* check for a pipe command */
+    if (prnpipe && !strcasecmp(fname, "PRN:"))
+	f = 'p';
+
+    if (auxpipe && !strcasecmp(fname, "AUX:"))
+	f = 'a';
+
+    if (f)
+    {
+	/* create new pipe */
+	for (i=0; i<MAXFILES && file[i].bp != 0; i++)
+	    ;
+	if (i >= MAXFILES)
+	{
+	    DREG(0) = TOS_ENMFIL;
+	    SET_Z();
+	    return;
+	}
+
+	if (f == 'a')
+	{
+	    file[i].lpp = popen(auxpipe, "w");
+	    DBG("Fcreate(%s) -> %s = %d ", fname, auxpipe, i+H_OFFSET);
+	} else if (f == 'p') {
+	    file[i].lpp = popen(prnpipe, "w");
+	    DBG("Fcreate(%s) -> %s = %d ", fname, prnpipe, i+H_OFFSET);
+	}
+
+	if (file[i].lpp)
+	{
+	    file[i].bp = bp;
+	    file[i].f = i;
+	    file[i].redirected = 0;
+	    DREG(0) = i+H_OFFSET;
+	    SET_Z();
+	    DBG("OK\n");
+	}
+	else
+	{
+	    DREG(0) = TOS_EACCDN;
+	    SET_Z();
+	    DBG("Failed\n");
+	}
+	return;
+    }
+#endif
+
     if (!st2unixpath(fname, upath))
     {
 	DBG("Fcreate(%s,%x) drive %d not done\n",fname,attribs,curdrv);
+	DREG(0) = TOS_EPTHNF;
+	SET_Z();
 	return;
     }
-    bp = LM_UL(act_pd);
     DBG("Fcreate(%s,%x) on drive %d -> %s\n",fname,attribs,curdrv,upath);
     if (attribs == FA_LABEL) {
 	DBG("\tDrivelabels cannot be created!\n");
@@ -813,7 +959,7 @@ void Fcreate (char *fname, UW attribs)
 	    return;
 	}
     
-    f = creat(upath,DEFAULT_MODE);
+    f = open(upath,O_CREAT|O_RDWR|O_TRUNC,DEFAULT_MODE);
     if (f < 0)
     {
 	DBG("creat(): %s\n",strerror(errno));
@@ -843,7 +989,12 @@ void Fwrite (W handle, UL count, char *buf)
 	SET_Z();
 	return;
     }
-    r = write (file[i].f, buf, (size_t) count);
+#if LPPIPES
+    if (file[i].lpp)
+	r = fwrite(buf, 1, (size_t) count, file[i].lpp);
+    else
+#endif
+	r = write (file[i].f, buf, (size_t) count);
     if ( r < 0 )
 	r = unix2toserrno( errno, TOS_EACCDN );
     DBG("\tReturnvalue for handle %d = %d\n",i+H_OFFSET,r);
@@ -856,6 +1007,7 @@ void Fdelete (char *fname)
 {
     char upath[500];
     if (!st2unixpath(fname,upath)) return;
+    DBG("Fdelete(%s) on drive %d <%s> = ",fname,curdrv,upath);
     if (unlink(upath) < 0)
     {
 	DREG(0) = unix2toserrno( errno, TOS_EACCDN );
@@ -864,13 +1016,14 @@ void Fdelete (char *fname)
     }
     DREG(0)=0;
     SET_Z();
-    return;
+    DBG("%d\n", DREG(0));
 }
 
 void Dcreate (char *pname)
 {
     char upath[500];
     if (!st2unixpath(pname,upath)) return;
+	DBG("Dcreate(%s) on drive %d <%s> = ",pname,curdrv,upath);
     if (mkdir(upath,DEFAULT_DIRMODE) < 0)
     {
 	DREG(0) = unix2toserrno(errno,TOS_EACCDN);
@@ -879,12 +1032,14 @@ void Dcreate (char *pname)
     }
     DREG(0)=0;
     SET_Z();
+    DBG("%d\n", DREG(0));
 }
 
 void Ddelete (char *pname)
 {
     char upath[500];
     if (!st2unixpath(pname,upath)) return;
+    DBG("Ddelete(%s) on drive %d <%s> = ",pname,curdrv,upath);
     if (rmdir(upath) < 0)
     {
 	DREG(0) = unix2toserrno(errno,TOS_EACCDN);
@@ -893,22 +1048,26 @@ void Ddelete (char *pname)
     }
     DREG(0)=0;
     SET_Z();
+    DBG("%d\n", DREG(0));
 }
 
 void Dgetpath (char *buf, UW drv)
 {
     /* FIXME */
+    DBG("Dgetpath(%d) = ",drv);
     if (drv == 0)
 	drv=curdrv;
     else
 	--drv;
     if (!((gemdos_drives >> drv)&1))
     {
+	DBG("(tos)\n");
 	return;
     }
     DREG(0) = 0;
     sprintf(buf,"%s",curpath[drv]);
     SET_Z();
+    DBG("%s\n",curpath[drv]);
 }
 
 void Pexec (UW mode, char *file, char *cmdlin, char *env)
@@ -957,13 +1116,25 @@ void Fseek (L offset, W handle, UW mode)
 	SET_Z();
 	return;
     }
+#if LPPIPES
+    /* do not allow seeking on lp pipe */ 
+    if (file[i].lpp)
+    {
+	DREG(0) = TOS_EACCDN;
+	SET_Z();
+	return;
+    }
+#endif
+
     dpos=lseek(file[i].f,0,SEEK_CUR);
     dlen=lseek(file[i].f,0,SEEK_END);
+    DBG("Fseek: file length is %ld\n",dlen);
     (void)lseek(file[i].f,dpos,SEEK_SET);
     dpos=lseek(file[i].f,offset,mode);
     if (dpos > dlen) DREG(0)=-64;	/* ERANGE */
     else DREG(0)=dpos;
     SET_Z();
+    DBG("Fseek(%d,%d,%d) = %d\n", offset, handle, mode, DREG(0));
     return;
 }
 
@@ -987,6 +1158,11 @@ void Fdatime (UW *t, UW *d, W handle, UW wflag)
 {
     struct stat s;
     int i=handle-H_OFFSET;
+    time_t time;
+    char link[500], f[500];
+    int len;
+    struct utimbuf ut;
+    DBG("Fdatime(%x,%i,%d)\n",t,handle,wflag);
     if (i<0) return;
     if (file[i].bp != LM_UL(act_pd) || file[i].f < 0)
     {
@@ -997,14 +1173,28 @@ void Fdatime (UW *t, UW *d, W handle, UW wflag)
     if (wflag == 0)
     {
 	fstat (file[i].f, &s);
-	SM_UW(t,s.st_mtime);
-	SM_UW(d,s.st_mtime);
+	SM_UW(t,time2dos(s.st_mtime));
+	SM_UW(d,date2dos(s.st_mtime));
 	DREG(0) = 0;
 	SET_Z();
 	return;
     }
     else if (wflag == 1)
     {
+	sprintf (link,"/proc/%d/fd/%d",getpid(),file[i].f); /* needs /proc-based OS (Linux) */
+	len = readlink (link,f,499);
+	if (len > 0)
+	{
+		f[len] = 0;
+		time = dos2time(LM_UW(t),LM_UW(d));
+		ut.actime = time;
+		ut.modtime = time;
+		utime(f,&ut);
+	}
+	else
+	{
+		DBG("Fdatime: could not read link \"%s\": %s\n",link,strerror(errno));
+	}
 	DREG(0) = 0;
 	SET_Z();
 	return;
@@ -1300,6 +1490,9 @@ void init_gemdos (void)
 	file[i].bp = 0;
 	file[i].f = -1;
 	file[i].redirected = 0;
+#if LPPIPES
+	file[i].lpp = NULL;
+#endif
     }
     for (i=0; i<6; i++ )
 	redirect_stdh[i][0] = -1;
