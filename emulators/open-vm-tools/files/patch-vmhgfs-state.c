--- modules/freebsd/vmhgfs/state.c.orig	2010-10-20 05:19:54.000000000 +0900
+++ modules/freebsd/vmhgfs/state.c	2010-11-16 13:27:57.000000000 +0900
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
@@ -1277,6 +1283,7 @@
  *----------------------------------------------------------------------------
  */
 
+#if 0 /* never used */
 void
 HgfsMarkFileMmapped(struct vnode *vp,    // vnode which state is being changed
                     Bool mmapped)        // New mapping state
@@ -1286,6 +1293,7 @@
    fp = HGFS_VP_TO_FP(vp);
    fp->mmapped = mmapped;
 }
+#endif
 
 /* Adding/finding/removing file state from hash table */
 
