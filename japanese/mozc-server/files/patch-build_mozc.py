--- build_mozc.py.orig	2012-03-16 10:48:09.087711537 +0900
+++ build_mozc.py	2012-03-16 10:59:56.396715771 +0900
@@ -70,7 +70,7 @@
 
 def IsLinux():
   """Returns true if the platform is Linux."""
-  return os.name == 'posix' and os.uname()[0] == 'Linux'
+  return os.name == 'posix' and ( os.uname()[0] == 'Linux' or os.uname()[0] == 'FreeBSD' )
 
 
 # TODO(yukawa): Move this function to util.py (b/2715400)
