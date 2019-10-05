--- src/calibre/constants.py.orig	2019-10-04 00:55:14 UTC
+++ src/calibre/constants.py
@@ -146,7 +146,7 @@ def _get_cache_dir():
 def cache_dir():
     ans = getattr(cache_dir, 'ans', None)
     if ans is None:
-        ans = cache_dir.ans = _get_cache_dir()
+        ans = cache_dir.ans = os.path.realpath(_get_cache_dir())
     return ans
 
 
