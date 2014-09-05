--- swift/common/utils.py.orig	2014-07-07 19:08:31.000000000 +0300
+++ swift/common/utils.py	2014-08-20 21:56:29.000000000 +0300
@@ -552,12 +552,12 @@
     """
     global _posix_fadvise
     if _posix_fadvise is None:
-        _posix_fadvise = load_libc_function('posix_fadvise64')
+        _posix_fadvise = load_libc_function('posix_fadvise')
     # 4 means "POSIX_FADV_DONTNEED"
     ret = _posix_fadvise(fd, ctypes.c_uint64(offset),
                          ctypes.c_uint64(length), 4)
     if ret != 0:
-        logging.warn("posix_fadvise64(%(fd)s, %(offset)s, %(length)s, 4) "
+        logging.warn("posix_fadvise(%(fd)s, %(offset)s, %(length)s, 4) "
                      "-> %(ret)s", {'fd': fd, 'offset': offset,
                                     'length': length, 'ret': ret})
 
