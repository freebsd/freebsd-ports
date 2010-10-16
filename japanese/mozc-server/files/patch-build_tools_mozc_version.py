--- build_tools/mozc_version.py.org	2010-10-16 11:59:00.003180328 +0900
+++ build_tools/mozc_version.py	2010-10-16 11:59:15.492182701 +0900
@@ -55,7 +55,7 @@
 
 def IsLinux():
   """Returns true if the platform is Linux."""
-  return os.name == 'posix' and os.uname()[0] == 'Linux'
+  return os.name == 'posix' and ( os.uname()[0] == 'Linux' or os.uname()[0] == 'FreeBSD' )
 
 
 def CalculateRevisionForPlatform(revision):
