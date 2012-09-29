--- ./setup.py.orig	2012-04-18 04:54:11.000000000 +1000
+++ ./setup.py	2012-09-25 21:54:06.000000000 +1000
@@ -20,13 +20,10 @@
         if self.distribution.has_ext_modules():
           self.run_command('build_ext')
 
-lib = ("hiredis", {
-  "sources": ["vendor/hiredis/%s.c" % src for src in ("hiredis", "net", "sds")],
-  "include_dirs": ["vendor/hiredis"]})
-
 ext = Extension("hiredis.hiredis",
   sources=glob.glob("src/*.c"),
-  include_dirs=["src", "vendor"],
+  include_dirs=["src", "%%LOCALBASE%%/include"],
+  library_dirs=["%%LOCALBASE%%/lib"],
   libraries=["hiredis"])
 
 setup(
@@ -39,7 +36,6 @@
   keywords=["Redis"],
   license="BSD",
   packages=["hiredis"],
-  libraries=[lib],
   ext_modules=[ext],
 
   # Override "install_lib" command
