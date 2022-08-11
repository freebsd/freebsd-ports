--- setup.py.orig	2021-03-28 15:11:23 UTC
+++ setup.py
@@ -11,9 +11,10 @@ def version():
   return module.__version__
 
 ext = Extension("hiredis.hiredis",
-  sources=sorted(glob.glob("src/*.c") +
-                 ["vendor/hiredis/%s.c" % src for src in ("alloc", "read", "sds")]),
-  include_dirs=["vendor"])
+  sources=sorted(glob.glob("src/*.c")),
+  include_dirs=["%%LOCALBASE%%/include"],
+  library_dirs=["%%LOCALBASE%%/lib"],
+  libraries=["hiredis"])
 
 setup(
   name="hiredis",
