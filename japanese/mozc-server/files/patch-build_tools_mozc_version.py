--- build_tools/mozc_version.py.orig	2012-04-02 08:17:52.764727837 +0900
+++ build_tools/mozc_version.py	2012-04-02 08:24:23.896726946 +0900
@@ -56,7 +56,7 @@
 
 def IsLinux():
   """Returns true if the platform is Linux."""
-  return os.name == 'posix' and os.uname()[0] == 'Linux'
+  return os.name == 'posix' and ( os.uname()[0] == 'Linux' or os.uname()[0] == 'FreeBSD' )
 
 
 def CalculateRevisionForPlatform(revision, target_platform):
