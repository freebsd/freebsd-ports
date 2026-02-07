--- raphodo/cache.py.orig	2019-07-31 17:16:30 UTC
+++ raphodo/cache.py
@@ -131,7 +131,7 @@ class Cache:
          not be generated)
         """
 
-        assert sys.platform.startswith('linux')
+        assert sys.platform.startswith('linux') or sys.platform.startswith('freebsd')
         self.cache_dir = cache_dir
         self.failure_dir = failure_dir
         assert self.cache_dir
