--- build_tools/mozc_version.py.org	2010-09-25 11:06:06.607334667 +0900
+++ build_tools/mozc_version.py	2010-09-25 11:06:24.382334562 +0900
@@ -55,7 +55,7 @@
 
 def IsLinux():
   """Returns true if the platform is Linux."""
-  return os.name == 'posix' and os.uname()[0] == 'Linux'
+  return os.name == 'posix' and ( os.uname()[0] == 'Linux' or os.uname()[0] == 'FreeBSD' )
 
 
 def CalculateRevisionForPlatform(revision):
