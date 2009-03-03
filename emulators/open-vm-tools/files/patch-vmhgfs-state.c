--- modules/freebsd/vmhgfs/state.c.orig	2009-02-28 23:06:10.000000000 +0100
+++ modules/freebsd/vmhgfs/state.c	2009-02-28 23:08:59.000000000 +0100
@@ -770,6 +770,12 @@
       goto destroyVnode;
    }
 
+#if __FreeBSD_version >= 700034
+   if ((ret = insmntque(vp, vfsp)) != 0) {
+      return ret;
+   }
+#endif
+
    /*
     * Now we'll initialize the vnode.  We need to set the file type, vnode
     * operations, flags, filesystem pointer, reference count, and device.
