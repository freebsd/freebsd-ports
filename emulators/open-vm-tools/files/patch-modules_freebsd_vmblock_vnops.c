--- modules/freebsd/vmblock/vnops.c.orig	2019-10-21 21:58:04 UTC
+++ modules/freebsd/vmblock/vnops.c
@@ -532,17 +532,12 @@ struct vop_generic_args {
     * Map the possible out-going vpp (Assumes that the lower layer always
     * returns a VREF'ed vpp unless it gets an error.)
     */
-   if (descp->vdesc_vpp_offset != VDESC_NO_OFFSET &&
-       !(descp->vdesc_flags & VDESC_NOMAP_VPP) &&
-       !error) {
+   if (descp->vdesc_vpp_offset != VDESC_NO_OFFSET && !error) {
       /*
        * XXX - even though some ops have vpp returned vp's, several ops
        * actually vrele this before returning.  We must avoid these ops.
        * (This should go away when these ops are regularized.)
        */
-      if (descp->vdesc_flags & VDESC_VPP_WILLRELE) {
-         goto out;
-      }
       vppp = VOPARG_OFFSETTO(struct vnode***, descp->vdesc_vpp_offset,ap);
       if (*vppp) {
          /* FIXME: set proper name for the vnode */
@@ -550,7 +545,6 @@ struct vop_generic_args {
       }
    }
 
-out:
    return error;
 }
 
@@ -1262,12 +1256,15 @@ struct vop_unlock_args {
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
@@ -1276,6 +1273,7 @@ struct vop_unlock_args {
       VI_UNLOCK(vp);
       ap->a_flags = flags &= ~LK_INTERLOCK;
    }
+#endif
    nn = VPTOVMB(vp);
    if (nn != NULL && (lvp = VMBVPTOLOWERVP(vp)) != NULL) {
       error = COMPAT_VOP_UNLOCK(lvp, flags, td);
