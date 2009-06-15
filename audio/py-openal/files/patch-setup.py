--- setup.py	Sun Apr 30 10:23:44 2006
+++ setup.py	Mon Aug 21 00:25:58 2006
@@ -1,14 +1,14 @@
 import os
 from distutils.core import setup, Extension
 
-LIBDIRS = ["/usr/lib", "/usr/local/lib"]
+LIBDIRS = ["/usr/lib", "/usr/local/lib", "%%LOCALBASE%%/lib"]
 LIBS    = ["openal", "alut"]
 
 try:
   openal_version = os.popen("openal-config --version").read()
   if openal_version[0] == "0":
-    LIBDIRS = ["/usr/lib", "/usr/local/lib"]
-    LIBS    = ["openal"]
+    LIBDIRS = ["/usr/lib", "/usr/local/lib", "%%LOCALBASE%%/lib"]
+    LIBS    = ["openal","alut"]
     
 except:
   print "Warning: error while running 'openal-config --version', using default values..."
@@ -38,7 +38,7 @@
   
   ext_modules  = [Extension("_openal",
                             ["py_openal.c"],
-                            ["/usr/include", "/usr/local/include"],
+                            ["/usr/include", "/usr/local/include", "%%LOCALBASE%%/include"],
                             [("HAVE_CONFIG_H", None)],
                             None,
                             LIBDIRS,
