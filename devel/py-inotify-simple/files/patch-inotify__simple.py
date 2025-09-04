--- inotify_simple.py.orig	2025-08-25 06:27:48 UTC
+++ inotify_simple.py
@@ -76,7 +76,7 @@ class INotify(FileIO):
                 object is garbage collected or when `~inotify_simple.INotify.close` is
                 called."""
             
-        global _libc; _libc = _libc or CDLL(find_library('c'), use_errno=True)
+        global _libc; _libc = _libc or CDLL(find_library('inotify'), use_errno=True)
         flags = (not inheritable) * os.O_CLOEXEC | bool(nonblocking) * os.O_NONBLOCK
         fd = _libc_call(_libc.inotify_init1, flags)
         super().__init__(fd, mode='rb', closefd=closefd)
