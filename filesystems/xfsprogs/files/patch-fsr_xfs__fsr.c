--- fsr/xfs_fsr.c.orig	2015-07-24 04:28:04 UTC
+++ fsr/xfs_fsr.c
@@ -26,15 +26,13 @@
 
 #include <fcntl.h>
 #include <errno.h>
-#include <malloc.h>
-#include <mntent.h>
+#include <sys/mount.h>
 #include <syslog.h>
 #include <signal.h>
 #include <sys/ioctl.h>
 #include <sys/wait.h>
-#include <sys/vfs.h>
 #include <sys/statvfs.h>
-#include <sys/xattr.h>
+#include <sys/extattr.h>
 
 
 #ifndef XFS_XFLAG_NODEFRAG
@@ -184,10 +182,13 @@ aborter(int unused)
 static char *
 find_mountpoint(char *mtab, char *argname, struct stat64 *sb)
 {
-	struct mntent *t;
+	struct statfs *t;
 	struct stat64 ms;
-	FILE *mtabp;
 	char *mntp = NULL;
+	int nt;
+
+#ifdef __linux__
+	FILE *mtabp;
 
 	mtabp = setmntent(mtab, "r");
 	if (!mtabp) {
@@ -195,40 +196,43 @@ find_mountpoint(char *mtab, char *argnam
 			progname, mtab);
 		exit(1);
 	}
+#endif
 
-	while ((t = getmntent(mtabp))) {
+	for (nt = getmntinfo(&t, MNT_NOWAIT); nt--; t++) {
 		if (S_ISDIR(sb->st_mode)) {		/* mount point */
-			if (stat64(t->mnt_dir, &ms) < 0)
+			if (stat64(t->f_mntonname, &ms) < 0)
 				continue;
 			if (sb->st_ino != ms.st_ino)
 				continue;
 			if (sb->st_dev != ms.st_dev)
 				continue;
-			if (strcmp(t->mnt_type, MNTTYPE_XFS) != 0)
+			if (strcmp(t->f_fstypename, MNTTYPE_XFS) != 0)
 				continue;
 		} else {				/* device */
 			struct stat64 sb2;
 
-			if (stat64(t->mnt_fsname, &ms) < 0)
+			if (stat64(t->f_mntfromname, &ms) < 0)
 				continue;
 			if (sb->st_rdev != ms.st_rdev)
 				continue;
-			if (strcmp(t->mnt_type, MNTTYPE_XFS) != 0)
+			if (strcmp(t->f_fstypename, MNTTYPE_XFS) != 0)
 				continue;
 
 			/*
 			 * Make sure the mountpoint given by mtab is accessible
 			 * before using it.
 			 */
-			if (stat64(t->mnt_dir, &sb2) < 0)
+			if (stat64(t->f_mntonname, &sb2) < 0)
 				continue;
 		}
 
-		mntp = t->mnt_dir;
+		mntp = t->f_mntonname;
 		break;
 	}
 
+#ifdef __linux__
 	endmntent(mtabp);
+#endif
 	return mntp;
 }
 
@@ -304,6 +308,7 @@ main(int argc, char **argv)
 		}
 	}
 
+#ifdef __linux__
 	/*
 	 * If the user did not specify an explicit mount table, try to use
 	 * /proc/mounts if it is available, else /etc/mtab.  We prefer
@@ -317,6 +322,7 @@ main(int argc, char **argv)
 		else
 			mtab = _PATH_MOUNTED;
 	}
+#endif
 
 	if (vflag)
 		setbuf(stdout, NULL);
@@ -392,7 +398,7 @@ usage(int ret)
 "       -t time         How long to run in seconds.\n"
 "       -p passes       Number of passes before terminating global re-org.\n"
 "       -f leftoff      Use this instead of %s.\n"
-"       -m mtab         Use something other than /etc/mtab.\n"
+"       -m mtab         Use this instead of /etc/mtab (ignored on FreeBSD).\n"
 "       -d              Debug, print even more.\n"
 "       -v              Verbose, more -v's more verbose.\n"
 "       -V              Print version number and exit.\n"
@@ -406,17 +412,20 @@ usage(int ret)
 static void
 initallfs(char *mtab)
 {
-	FILE *fp;
-	struct mntent *mp;
-	int mi;
+	struct statfs *mp;
+	int mi, nmp;
 	char *cp;
 	struct stat64 sb;
 
+#ifdef __linux__
+	FILE *fp;
+
 	fp = setmntent(mtab, "r");
 	if (fp == NULL) {
 		fsrprintf(_("could not open mtab file: %s\n"), mtab);
 		exit(1);
 	}
+#endif
 
 	/* malloc a number of descriptors, increased later if needed */
 	if (!(fsbase = (fsdesc_t *)malloc(fsbufsize * sizeof(fsdesc_t)))) {
@@ -428,23 +437,19 @@ initallfs(char *mtab)
 	/* find all rw xfs file systems */
 	mi = 0;
 	fs = fsbase;
-	while ((mp = getmntent(fp))) {
+	for (nmp = getmntinfo(&mp, MNT_NOWAIT); nmp--; mp++) {
 		int rw = 0;
 
-		if (strcmp(mp->mnt_type, MNTTYPE_XFS ) != 0 ||
-		    stat64(mp->mnt_fsname, &sb) == -1 ||
+		if (strcmp(mp->f_fstypename, MNTTYPE_XFS ) != 0 ||
+		    stat64(mp->f_mntfromname, &sb) == -1 ||
 		    !S_ISBLK(sb.st_mode))
 			continue;
 
-		cp = strtok(mp->mnt_opts,",");
-		do {
-			if (strcmp("rw", cp) == 0)
-				rw++;
-		} while ((cp = strtok(NULL, ",")) != NULL);
+		rw = !(mp->f_flags & MNT_RDONLY);
 		if (rw == 0) {
 			if (dflag)
 				fsrprintf(_("Skipping %s: not mounted rw\n"),
-					mp->mnt_fsname);
+					mp->f_mntfromname);
 			continue;
 		}
 
@@ -464,15 +469,15 @@ initallfs(char *mtab)
 			fs = (fsbase + mi);  /* Needed ? */
 		}
 
-		fs->dev = strdup(mp->mnt_fsname);
-		fs->mnt = strdup(mp->mnt_dir);
+		fs->dev = strdup(mp->f_mntfromname);
+		fs->mnt = strdup(mp->f_mntonname);
 
 		if (fs->dev == NULL) {
-			fsrprintf(_("strdup(%s) failed\n"), mp->mnt_fsname);
+			fsrprintf(_("strdup(%s) failed\n"), mp->f_mntfromname);
 			exit(1);
 		}
 		if (fs->mnt == NULL) {
-			fsrprintf(_("strdup(%s) failed\n"), mp->mnt_dir);
+			fsrprintf(_("strdup(%s) failed\n"), mp->f_mntonname);
 			exit(1);
 		}
 		mi++;
@@ -480,7 +485,9 @@ initallfs(char *mtab)
 	}
 	numfs = mi;
 	fsend = (fsbase + numfs);
+#ifdef __linux__
 	endmntent(fp);
+#endif
 	if (numfs == 0) {
 		fsrprintf(_("no rw xfs file systems in mtab: %s\n"), mtab);
 		exit(0);
@@ -1027,7 +1034,7 @@ fsr_setup_attr_fork(
 	xfs_bstat_t	*bstatp)
 {
 	struct stat64	tstatbuf;
-	int		i;
+	int		i, ns;
 	int		diff = 0;
 	int		last_forkoff = 0;
 	int		no_change_cnt = 0;
@@ -1036,6 +1043,9 @@ fsr_setup_attr_fork(
 	if (!(bstatp->bs_xflags & XFS_XFLAG_HASATTR))
 		return 0;
 
+	if (extattr_string_to_namespace("user", &ns) == -1)
+		return -1;
+
 	/*
 	 * use the old method if we have attr1 or the kernel does not yet
 	 * support passing the fork offset in the bulkstat data.
@@ -1043,8 +1053,8 @@ fsr_setup_attr_fork(
 	if (!(fsgeom.flags & XFS_FSOP_GEOM_FLAGS_ATTR2) ||
 	    bstatp->bs_forkoff == 0) {
 		/* attr1 */
-		ret = fsetxattr(tfd, "user.X", "X", 1, XATTR_CREATE);
-		if (ret) {
+		ret = extattr_set_fd(tfd, ns, "X", "X", 1);
+		if (ret == -1) {
 			fsrprintf(_("could not set ATTR\n"));
 			return -1;
 		}
@@ -1085,7 +1095,7 @@ fsr_setup_attr_fork(
 		if (!diff)
 			goto out;
 
-		snprintf(name, sizeof(name), "user.%d", i);
+		snprintf(name, sizeof(name), "%d", i);
 
 		/*
 		 * If there is no attribute, then we need to create one to get
@@ -1093,8 +1103,8 @@ fsr_setup_attr_fork(
 		 */
 		if (!tbstat.bs_forkoff) {
 			ASSERT(i == 0);
-			ret = fsetxattr(tfd, name, "XX", 2, XATTR_CREATE);
-			if (ret) {
+			ret = extattr_set_fd(tfd, ns, name, "XX", 2);
+			if (ret == -1) {
 				fsrprintf(_("could not set ATTR\n"));
 				return -1;
 			}
@@ -1141,7 +1151,8 @@ fsr_setup_attr_fork(
  			if (diff < 0 && fsx.fsx_nextents > 0) {
 				char val[2048];
 				memset(val, 'X', 2048);
-				if (fsetxattr(tfd, name, val, 2048, 0)) {
+				if (extattr_set_fd(tfd, ns, name, val, 2048)
+				    == -1) {
 					fsrprintf(_("big ATTR set failed\n"));
 					return -1;
 				}
@@ -1185,8 +1196,8 @@ fsr_setup_attr_fork(
 		}
 
 		/* we need to grow the attr fork, so create another attr */
-		ret = fsetxattr(tfd, name, "XX", 2, XATTR_CREATE);
-		if (ret) {
+		ret = extattr_set_fd(tfd, ns, name, "XX", 2);
+		if (ret == -1) {
 			fsrprintf(_("could not set ATTR\n"));
 			return -1;
 		}
