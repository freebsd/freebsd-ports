--- build_mozc.py.orig	2012-01-29 13:42:31.525804671 +0900
+++ build_mozc.py	2012-01-29 13:49:21.572805896 +0900
@@ -70,7 +70,7 @@
 
 def IsLinux():
   """Returns true if the platform is Linux."""
-  return os.name == 'posix' and os.uname()[0] == 'Linux'
+  return os.name == 'posix' and ( os.uname()[0] == 'Linux' or os.uname()[0] == 'FreeBSD' )
 
 
 # TODO(yukawa): Move this function to util.py (b/2715400)
