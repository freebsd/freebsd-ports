--- build_mozc.py.org	2010-09-25 11:04:25.422333501 +0900
+++ build_mozc.py	2010-10-03 12:55:53.425314392 +0900
@@ -69,7 +69,7 @@
 
 def IsLinux():
   """Returns true if the platform is Linux."""
-  return os.name == 'posix' and os.uname()[0] == 'Linux'
+  return os.name == 'posix' and ( os.uname()[0] == 'Linux' or os.uname()[0] == 'FreeBSD' )
 
 
 # TODO(yukawa): Move this function to util.py (b/2715400)
