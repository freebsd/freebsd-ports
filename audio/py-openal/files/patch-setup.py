--- setup.py.orig	2006-04-30 15:23:44 UTC
+++ setup.py
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
@@ -38,7 +38,7 @@ Does not include OpenAL extension.""",
   
   ext_modules  = [Extension("_openal",
                             ["py_openal.c"],
-                            ["/usr/include", "/usr/local/include"],
+                            ["/usr/include", "/usr/local/include", "%%LOCALBASE%%/include"],
                             [("HAVE_CONFIG_H", None)],
                             None,
                             LIBDIRS,
