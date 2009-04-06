--- modules/freebsd/vmblock/subr.c.orig	2009-02-28 23:04:14.000000000 +0100
+++ modules/freebsd/vmblock/subr.c	2009-02-28 23:05:38.000000000 +0100
@@ -334,7 +334,12 @@
    vp->v_vnlock = &vp->v_lock;
    FREE(xp, M_VMBLOCKFSNODE);
    vp->v_op = &dead_vnodeops;
+
+#if __FreeBSD_version >= 800011
+   (void) vn_lock(vp, LK_EXCLUSIVE | LK_RETRY);
+#else
    (void) vn_lock(vp, LK_EXCLUSIVE | LK_RETRY, curthread);
+#endif
    vgone(vp);
    vput(vp);
 }
@@ -405,6 +410,13 @@
       return error;
    }
 
+#if __FreeBSD_version >= 700034
+   if ((error = insmntque(vp, mp)) != 0) {
+      free(xp, M_VMBLOCKFSNODE);
+      return error;
+   }
+#endif
+
    xp->backVnode = vp;
    xp->lowerVnode = lowervp;
    vp->v_type = lowervp->v_type;
