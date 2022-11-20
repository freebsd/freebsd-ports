--- src/watchdog/observers/inotify_c.py.orig	2022-06-10 10:11:14 UTC
+++ src/watchdog/observers/inotify_c.py
@@ -25,7 +25,7 @@ from functools import reduce
 from ctypes import c_int, c_char_p, c_uint32
 from watchdog.utils import UnsupportedLibc
 
-libc = ctypes.CDLL(None)
+libc = ctypes.CDLL('libinotify.so')
 
 if not hasattr(libc, 'inotify_init') or \
         not hasattr(libc, 'inotify_add_watch') or \
