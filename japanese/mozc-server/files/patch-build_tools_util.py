--- build_tools/util.py.orig	2012-05-29 15:37:00.289960660 +0900
+++ build_tools/util.py	2012-05-01 13:03:43.227693771 +0900
@@ -54,7 +54,7 @@
 
 def IsLinux():
   """Returns true if the platform is Linux."""
-  return os.name == 'posix' and os.uname()[0] == 'Linux'
+  return os.name == 'posix' and ( os.uname()[0] == 'Linux' or os.uname()[0] == 'FreeBSD' )
 
 
 def GetNumberOfProcessors():
