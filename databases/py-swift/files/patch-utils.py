--- swift/common/utils.py.orig	2013-05-18 14:10:21.000000000 +0300
+++ swift/common/utils.py	2013-05-18 14:09:06.000000000 +0300
@@ -274,12 +274,12 @@ def drop_buffer_cache(fd, offset, length
     """
     global _posix_fadvise
     if _posix_fadvise is None:
-        _posix_fadvise = load_libc_function('posix_fadvise64')
+        _posix_fadvise = load_libc_function('posix_fadvise')
     # 4 means "POSIX_FADV_DONTNEED"
     ret = _posix_fadvise(fd, ctypes.c_uint64(offset),
                          ctypes.c_uint64(length), 4)
     if ret != 0:
-        logging.warn("posix_fadvise64(%s, %s, %s, 4) -> %s"
+        logging.warn("posix_fadvise(%s, %s, %s, 4) -> %s"
                      % (fd, offset, length, ret))
 
 
