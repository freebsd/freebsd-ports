--- modules/freebsd/vmblock/vnops.c.orig	2019-10-21 21:58:04 UTC
+++ modules/freebsd/vmblock/vnops.c
@@ -1262,12 +1262,15 @@ struct vop_unlock_args {
 */
 {
    struct vnode *vp = ap->a_vp;
+#if __FreeBSD_version < 1300074
    int flags = ap->a_flags;
+#endif
    COMPAT_THREAD_VAR(td, ap->a_td);
    struct VMBlockNode *nn;
    struct vnode *lvp;
    int error;
 
+#if __FreeBSD_version < 1300074
    /*
     * If caller already holds interlock, drop it.  (Per VOP_UNLOCK() API.)
     * Also strip LK_INTERLOCK from flags passed to lower layer.
@@ -1276,6 +1279,7 @@ struct vop_unlock_args {
       VI_UNLOCK(vp);
       ap->a_flags = flags &= ~LK_INTERLOCK;
    }
+#endif
    nn = VPTOVMB(vp);
    if (nn != NULL && (lvp = VMBVPTOLOWERVP(vp)) != NULL) {
       error = COMPAT_VOP_UNLOCK(lvp, flags, td);
