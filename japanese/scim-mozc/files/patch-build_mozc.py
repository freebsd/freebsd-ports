--- build_mozc.py.org	2010-10-16 11:58:32.818179161 +0900
+++ build_mozc.py	2010-10-16 11:58:50.886185011 +0900
@@ -69,7 +69,7 @@
 
 def IsLinux():
   """Returns true if the platform is Linux."""
-  return os.name == 'posix' and os.uname()[0] == 'Linux'
+  return os.name == 'posix' and ( os.uname()[0] == 'Linux' or os.uname()[0] == 'FreeBSD' )
 
 
 # TODO(yukawa): Move this function to util.py (b/2715400)
