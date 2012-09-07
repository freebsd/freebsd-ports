--- build_tools/util.py.orig	2012-09-07 10:21:29.190021513 +0900
+++ build_tools/util.py	2012-09-07 10:30:26.180021509 +0900
@@ -54,7 +54,7 @@
 
 def IsLinux():
   """Returns true if the platform is Linux."""
-  return os.name == 'posix' and os.uname()[0] == 'Linux'
+  return os.name == 'posix' and ( os.uname()[0] == 'Linux' or os.uname()[0] == 'FreeBSD' )
 
 
 def GetNumberOfProcessors():
