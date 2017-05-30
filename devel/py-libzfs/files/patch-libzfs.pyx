--- libzfs.pyx.orig	2017-05-26 01:20:43 UTC
+++ libzfs.pyx
@@ -2131,7 +2131,7 @@ cdef class ZFSObject(object):
             cfromname = fromname
 
         with nogil:
-            ret = libzfs.lzc_send_space(c_name, cfromname, &space)
+            ret = libzfs.lzc_send_space(c_name, cfromname, 0, &space)
 
         if ret != 0:
             raise ZFSException(Error.FAULT, "Cannot obtain space estimate: ")
@@ -2275,7 +2275,8 @@ cdef class ZFSDataset(ZFSObject):
             if libzfs.zfs_is_mounted(self.handle, &mntpt) == 0:
                 return None
 
-            result = mntpt
+            encoded = mntpt.encode('utf-8')
+            result = encoded
             free(mntpt)
             return result
 
