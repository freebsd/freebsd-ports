--- modules/freebsd/vmblock/vfsops.c	2007-11-21 09:10:18.000000000 +0100
+++ modules/freebsd/vmblock/vfsops.c	2007-12-06 12:26:47.000000000 +0100
@@ -217,7 +217,7 @@
     */
    MNT_ILOCK(mp);
    mp->mnt_flag |= lowerrootvp->v_mount->mnt_flag & MNT_LOCAL;
-#if BSD_VERSION >= 60
+#if __FreeBSD_version >= 60
    mp->mnt_kern_flag |= lowerrootvp->v_mount->mnt_kern_flag & MNTK_MPSAFE;
 #endif
    MNT_IUNLOCK(mp);
