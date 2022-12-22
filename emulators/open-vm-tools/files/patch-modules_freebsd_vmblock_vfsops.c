--- modules/freebsd/vmblock/vfsops.c.orig	2022-11-29 21:17:22 UTC
+++ modules/freebsd/vmblock/vfsops.c
@@ -171,14 +171,21 @@ VMBlockVFSMount(struct mount *mp,        // IN: mount(
     * Find lower node and lock if not already locked.
     */
 
+#if __FreeBSD_version >= 1400043
+   NDINIT(ndp, LOOKUP, FOLLOW|LOCKLEAF, UIO_SYSSPACE, target);
+#else
    NDINIT(ndp, LOOKUP, FOLLOW|LOCKLEAF, UIO_SYSSPACE, target, compat_td);
+#endif
    error = namei(ndp);
    if (error) {
-      NDFREE(ndp, 0);
       uma_zfree(VMBlockPathnameZone, pathname);
       return error;
    }
+#if __FreeBSD_version < 1400054
    NDFREE(ndp, NDF_ONLY_PNBUF);
+#else
+   NDFREE_PNBUF(ndp);
+#endif
 
    /*
     * Check multi VMBlock mount to avoid `lock against myself' panic.
