--- inotify_simple.py.orig	2024-02-11 00:28:11 UTC
+++ inotify_simple.py
@@ -82,7 +82,7 @@ class INotify(FileIO):
                 manually with ``os.read(fd)``) to raise ``BlockingIOError`` if no data
                 is available."""
         try:
-            libc_so = find_library('c')
+            libc_so = find_library('inotify')
         except RuntimeError: # Python on Synology NASs raises a RuntimeError
             libc_so = None
         global _libc; _libc = _libc or CDLL(libc_so or 'libc.so.6', use_errno=True)
