--- build_tools/mozc_version.py.orig	2011-12-24 13:17:12.978092858 +0900
+++ build_tools/mozc_version.py	2011-12-04 16:35:15.156605950 +0900
@@ -56,7 +56,7 @@
 
 def IsLinux():
   """Returns true if the platform is Linux."""
-  return os.name == 'posix' and os.uname()[0] == 'Linux'
+  return os.name == 'posix' and ( os.uname()[0] == 'Linux' or os.uname()[0] == 'FreeBSD' )
 
 
 def CalculateRevisionForPlatform(revision, target_platform):
