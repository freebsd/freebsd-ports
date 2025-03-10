--- vmblock/vfsops.c.orig	2024-10-10 15:05:07 UTC
+++ vmblock/vfsops.c
@@ -173,7 +173,6 @@ VMBlockVFSMount(struct mount *mp)        // IN: mount(
 #endif
    error = namei(ndp);
    if (error) {
-      NDFREE(ndp, 0);
       uma_zfree(VMBlockPathnameZone, pathname);
       return error;
    }
