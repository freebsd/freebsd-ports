--- src/build_tools/util.py.orig	2013-04-21 03:48:52.147271754 +0900
+++ src/build_tools/util.py	2013-04-21 04:07:17.415269142 +0900
@@ -54,7 +54,7 @@
 
 def IsLinux():
   """Returns true if the platform is Linux."""
-  return os.name == 'posix' and os.uname()[0] == 'Linux'
+  return os.name == 'posix' and ( os.uname()[0] == 'Linux' or os.uname()[0] == 'FreeBSD' )
 
 
 def GetNumberOfProcessors():
