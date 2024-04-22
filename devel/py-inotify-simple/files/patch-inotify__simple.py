--- inotify_simple.py.orig	2020-08-06 00:20:49 UTC
+++ inotify_simple.py
@@ -4,6 +4,7 @@ from enum import Enum, IntEnum
 from collections import namedtuple
 from struct import unpack_from, calcsize
 from select import poll
+from select import POLLIN
 from time import sleep
 from ctypes import CDLL, get_errno, c_int
 from ctypes.util import find_library
@@ -82,7 +83,7 @@ class INotify(FileIO):
                 manually with ``os.read(fd)``) to raise ``BlockingIOError`` if no data
                 is available."""
         try:
-            libc_so = find_library('c')
+            libc_so = find_library('inotify')
         except RuntimeError: # Python on Synology NASs raises a RuntimeError
             libc_so = None
         global _libc; _libc = _libc or CDLL(libc_so or 'libc.so.6', use_errno=True)
@@ -90,7 +91,7 @@ class INotify(FileIO):
         flags = (not inheritable) * O_CLOEXEC | bool(nonblocking) * os.O_NONBLOCK 
         FileIO.__init__(self, _libc_call(_libc.inotify_init1, flags), mode='rb')
         self._poller = poll()
-        self._poller.register(self.fileno())
+        self._poller.register(self.fileno(), POLLIN)
 
     def add_watch(self, path, mask):
         """Wrapper around ``inotify_add_watch()``. Returns the watch
