--- setup.py	Sun Apr 30 10:23:44 2006
+++ setup.py	Wed May 10 09:25:22 2006
@@ -1,13 +1,13 @@
 import os
 from distutils.core import setup, Extension
 
-LIBDIRS = ["/usr/lib", "/usr/local/lib"]
+LIBDIRS = ["/usr/lib", "/usr/local/lib", "%%PREFIX%%/lib"]
 LIBS    = ["openal", "alut"]
 
 try:
   openal_version = os.popen("openal-config --version").read()
   if openal_version[0] == "0":
-    LIBDIRS = ["/usr/lib", "/usr/local/lib"]
+    LIBDIRS = ["/usr/lib", "/usr/local/lib", "%%PREFIX%%/lib"]
     LIBS    = ["openal"]
     
 except:
@@ -38,7 +38,7 @@
   
   ext_modules  = [Extension("_openal",
                             ["py_openal.c"],
-                            ["/usr/include", "/usr/local/include"],
+                            ["/usr/include", "/usr/local/include", "%%PREFIX%%/include"],
                             [("HAVE_CONFIG_H", None)],
                             None,
                             LIBDIRS,
