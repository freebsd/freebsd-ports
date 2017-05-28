--- libzfs.pyx.orig	2017-05-28 14:29:59 UTC
+++ libzfs.pyx
@@ -2258,7 +2258,8 @@ cdef class ZFSDataset(ZFSObject):
             if libzfs.zfs_is_mounted(self.handle, &mntpt) == 0:
                 return None
 
-            result = mntpt
+            encoded = mntpt.encode('utf-8')
+            result = encoded
             free(mntpt)
             return result
 
