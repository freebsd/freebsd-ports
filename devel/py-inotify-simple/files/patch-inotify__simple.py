--- inotify_simple.py.orig	2025-08-25 06:27:48 UTC
+++ inotify_simple.py
@@ -3,6 +3,7 @@ from enum import IntEnum
 from collections import namedtuple
 from struct import unpack_from, calcsize
 from select import poll
+from select import POLLIN
 from time import sleep
 from ctypes import CDLL, get_errno, c_int
 from ctypes.util import find_library
@@ -76,12 +77,12 @@ class INotify(FileIO):
                 object is garbage collected or when `~inotify_simple.INotify.close` is
                 called."""
             
-        global _libc; _libc = _libc or CDLL(find_library('c'), use_errno=True)
+        global _libc; _libc = _libc or CDLL(find_library('inotify'), use_errno=True)
         flags = (not inheritable) * os.O_CLOEXEC | bool(nonblocking) * os.O_NONBLOCK
         fd = _libc_call(_libc.inotify_init1, flags)
         super().__init__(fd, mode='rb', closefd=closefd)
         self._poller = poll()
-        self._poller.register(self.fileno())
+        self._poller.register(self.fileno(), POLLIN)
 
     def add_watch(self, path, mask):
         """Wrapper around ``inotify_add_watch()``. Returns the watch
