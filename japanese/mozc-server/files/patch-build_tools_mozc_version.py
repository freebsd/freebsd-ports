--- build_tools/mozc_version.py.orig	2012-01-29 13:42:31.190807067 +0900
+++ build_tools/mozc_version.py	2012-01-29 13:49:15.791805587 +0900
@@ -56,7 +56,7 @@
 
 def IsLinux():
   """Returns true if the platform is Linux."""
-  return os.name == 'posix' and os.uname()[0] == 'Linux'
+  return os.name == 'posix' and ( os.uname()[0] == 'Linux' or os.uname()[0] == 'FreeBSD' )
 
 
 def CalculateRevisionForPlatform(revision, target_platform):
