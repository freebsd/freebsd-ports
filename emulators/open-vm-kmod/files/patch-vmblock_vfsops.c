--- vmblock/vfsops.c.orig	2025-10-01 18:44:42 UTC
+++ vmblock/vfsops.c
@@ -173,7 +173,6 @@ VMBlockVFSMount(struct mount *mp)        // IN: mount(
 #endif
    error = namei(ndp);
    if (error) {
-      NDFREE(ndp, 0);
       uma_zfree(VMBlockPathnameZone, pathname);
       return error;
    }
@@ -354,7 +353,7 @@ VMBlockVFSRoot(struct mount *mp,        // IN: vmblock
     * Return locked reference to root.
     */
    vp = MNTTOVMBLOCKMNT(mp)->rootVnode;
-   VREF(vp);
+   vref(vp);
    compat_vn_lock(vp, flags | LK_RETRY, compat_td);
    *vpp = vp;
    return 0;
