--- modules/freebsd/vmblock/vfsops.c.orig	2023-03-10 17:41:18 UTC
+++ modules/freebsd/vmblock/vfsops.c
@@ -173,7 +173,6 @@ VMBlockVFSMount(struct mount *mp)        // IN: mount(
 #endif
    error = namei(ndp);
    if (error) {
-      NDFREE(ndp, 0);
       uma_zfree(VMBlockPathnameZone, pathname);
       return error;
    }
