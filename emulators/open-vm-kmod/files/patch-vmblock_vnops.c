--- vmblock/vnops.c.orig	2025-10-01 18:40:23 UTC
+++ vmblock/vnops.c
@@ -479,9 +479,9 @@ struct vop_generic_args {
        * Check for and don't map any that aren't.  (We must always map first
        * vp or vclean fails.)
        */
-      if (i && (*this_vp_p == NULLVP ||
+      if (i && (*this_vp_p == NULL ||
           (*this_vp_p)->v_op != &VMBlockVnodeOps)) {
-         old_vps[i] = NULLVP;
+         old_vps[i] = NULL;
       } else {
          old_vps[i] = *this_vp_p;
          *(vps_p[i]) = VMBVPTOLOWERVP(*this_vp_p);
@@ -491,7 +491,7 @@ struct vop_generic_args {
           * future.)
           */
          if (reles & VDESC_VP0_WILLRELE) {
-            VREF(*this_vp_p);
+            vref(*this_vp_p);
          }
       }
    }
@@ -501,7 +501,7 @@ struct vop_generic_args {
     * structure.
     */
    if (vps_p[0] && *vps_p[0]) {
-      error = VCALL(ap);
+      error = ap->a_desc->vdesc_call(ap);
    } else {
       printf("VMBlockVopBypass: no map for %s\n", descp->vdesc_name);
       error = EINVAL;
@@ -681,7 +681,7 @@ struct vop_lookup_args {
        */
       if (ldvp == lvp) {
          *ap->a_vpp = dvp;
-         VREF(dvp);
+         vref(dvp);
          vrele(lvp);
       } else {
          error = VMBlockNodeGet(dvp->v_mount, lvp, &vp, pathname);
