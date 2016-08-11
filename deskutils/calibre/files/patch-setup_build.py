--- setup/build.py.orig	2016-07-22 02:21:05 UTC
+++ setup/build.py
@@ -79,7 +79,7 @@ def is_ext_allowed(ext):
     only = ext.get('only', '')
     if only:
         only = only.split()
-        q = 'windows' if iswindows else 'osx' if isosx else 'linux'
+        q = 'windows' if iswindows else 'osx' if isosx else 'bsd' if isbsd else 'linux'
         return q in only
     return True
 
@@ -94,6 +94,8 @@ def parse_extension(ext):
             ans = ext.pop('windows_' + k, ans)
         elif isosx:
             ans = ext.pop('osx_' + k, ans)
+        elif isbsd:
+            ans = ext.pop('bsd_' + k, ans)
         else:
             ans = ext.pop('linux_' + k, ans)
         return ans
