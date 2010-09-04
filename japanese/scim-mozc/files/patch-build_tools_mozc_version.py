--- build_tools/mozc_version.py.org	2010-09-03 14:19:13.609379202 +0900
+++ build_tools/mozc_version.py	2010-09-03 14:18:44.423726277 +0900
@@ -55,7 +55,7 @@
 
 def IsLinux():
   """Returns true if the platform is Linux."""
-  return os.name == 'posix' and os.uname()[0] == 'Linux'
+  return os.name == 'posix' and os.uname()[0] == 'FreeBSD'
 
 
 def CalculateRevisionForPlatform(revision):
