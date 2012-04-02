--- build_mozc.py.orig	2012-04-02 08:17:58.918726529 +0900
+++ build_mozc.py	2012-04-02 08:38:43.715726567 +0900
@@ -76,7 +76,7 @@
 
 def IsLinux():
   """Returns true if the platform is Linux."""
-  return os.name == 'posix' and os.uname()[0] == 'Linux'
+  return os.name == 'posix' and ( os.uname()[0] == 'Linux' or os.uname()[0] == 'FreeBSD' )
 
 
 # TODO(yukawa): Move this function to util.py (b/2715400)
