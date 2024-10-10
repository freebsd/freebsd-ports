--- lib/mount_bsd.c.orig	2015-05-22 09:24:02 UTC
+++ lib/mount_bsd.c
@@ -10,6 +10,8 @@
 #include "fuse_misc.h"
 #include "fuse_opt.h"
 
+#include <sys/param.h>
+#include <sys/mount.h>
 #include <sys/stat.h>
 #include <sys/wait.h>
 #include <sys/sysctl.h>
@@ -78,6 +80,7 @@ static const struct fuse_opt fuse_mount_
 	FUSE_DUAL_OPT_KEY("ro",			KEY_KERN),
 	FUSE_DUAL_OPT_KEY("rw",			KEY_KERN),
 	FUSE_DUAL_OPT_KEY("auto",		KEY_KERN),
+	FUSE_DUAL_OPT_KEY("automounted",	KEY_KERN),
 	/* options supported under both Linux and FBSD */
 	FUSE_DUAL_OPT_KEY("allow_other",	KEY_KERN),
 	FUSE_DUAL_OPT_KEY("default_permissions",KEY_KERN),
@@ -192,56 +195,12 @@ void fuse_unmount_compat22(const char *m
 	free(umount_cmd);
 }
 
-static void do_unmount(char *dev, int fd)
-{
-	char device_path[SPECNAMELEN + 12];
-	const char *argv[4];
-	const char umount_cmd[] = "/sbin/umount";
-	pid_t pid;
-
-	snprintf(device_path, SPECNAMELEN + 12, _PATH_DEV "%s", dev);
-
-	argv[0] = umount_cmd;
-	argv[1] = "-f";
-	argv[2] = device_path;
-	argv[3] = NULL;
-
-	pid = fork();
-
-	if (pid == -1)
-		return;
-
-	if (pid == 0) {
-		close(fd);
-		execvp(umount_cmd, (char **)argv);
-		exit(1);
-	}
-
-	waitpid(pid, NULL, 0);
-}
-
 void fuse_kern_unmount(const char *mountpoint, int fd)
 {
 	char *ep, dev[128];
 	struct stat sbuf;
 
-	(void)mountpoint;
-
-	if (fstat(fd, &sbuf) == -1)
-		goto out;
-
-	devname_r(sbuf.st_rdev, S_IFCHR, dev, 128);
-
-	if (strncmp(dev, "fuse", 4))
-		goto out;
-
-	strtol(dev + 4, &ep, 10);
-	if (*ep != '\0')
-		goto out;
-
-	do_unmount(dev, fd);
-
-out:
+	unmount(mountpoint, MNT_FORCE);
 	close(fd);
 }
 
