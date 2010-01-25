--- setup.py.orig	2006-04-30 17:23:44.000000000 +0200
+++ setup.py	2009-12-26 17:50:57.000000000 +0100
@@ -1,17 +1,17 @@
 import os
 from distutils.core import setup, Extension
 
-LIBDIRS = ["/usr/lib", "/usr/local/lib"]
+LIBDIRS = ["/usr/lib", "/usr/local/lib", "%%LOCALBASE%%/lib"]
 LIBS    = ["openal", "alut"]
 
 try:
-  openal_version = os.popen("openal-config --version").read()
+  openal_version = os.popen("pkg-config --modversion openal").read()
   if openal_version[0] == "0":
-    LIBDIRS = ["/usr/lib", "/usr/local/lib"]
-    LIBS    = ["openal"]
+    LIBDIRS = ["/usr/lib", "/usr/local/lib", "%%LOCALBASE%%/lib"]
+    LIBS    = ["openal","alut"]
     
 except:
-  print "Warning: error while running 'openal-config --version', using default values..."
+  print "Warning: error while running 'pkg-config --modversion', using default values..."
 
 
 setup(
@@ -38,7 +38,7 @@
   
   ext_modules  = [Extension("_openal",
                             ["py_openal.c"],
-                            ["/usr/include", "/usr/local/include"],
+                            ["/usr/include", "/usr/local/include", "%%LOCALBASE%%/include"],
                             [("HAVE_CONFIG_H", None)],
                             None,
                             LIBDIRS,
