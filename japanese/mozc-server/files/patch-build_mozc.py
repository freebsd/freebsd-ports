--- build_mozc.py.orig	2011-12-24 13:17:28.363092915 +0900
+++ build_mozc.py	2011-12-24 13:35:51.596092253 +0900
@@ -70,7 +70,7 @@
 
 def IsLinux():
   """Returns true if the platform is Linux."""
-  return os.name == 'posix' and os.uname()[0] == 'Linux'
+  return os.name == 'posix' and ( os.uname()[0] == 'Linux' or os.uname()[0] == 'FreeBSD' )
 
 
 # TODO(yukawa): Move this function to util.py (b/2715400)
