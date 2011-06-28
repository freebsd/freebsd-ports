--- build_tools/mozc_version.py.org	2010-11-06 10:46:40.900188220 +0900
+++ build_tools/mozc_version.py	2010-11-06 10:47:03.466651555 +0900
@@ -55,7 +55,7 @@
 
 def IsLinux():
   """Returns true if the platform is Linux."""
-  return os.name == 'posix' and os.uname()[0] == 'Linux'
+  return os.name == 'posix' and ( os.uname()[0] == 'Linux' or os.uname()[0] == 'FreeBSD' )
 
 
 def CalculateRevisionForPlatform(revision):
