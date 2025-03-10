--- setup.py.orig	2024-07-19 12:05:48 UTC
+++ setup.py
@@ -18,8 +18,7 @@ def get_sources():
 
 
 def get_sources():
-    hiredis_sources = ("alloc", "async", "hiredis", "net", "read", "sds", "sockcompat")
-    return sorted(glob.glob("src/*.c") + ["vendor/hiredis/%s.c" % src for src in hiredis_sources])
+    return sorted(glob.glob("src/*.c"))
 
 
 def get_linker_args():
@@ -47,8 +46,9 @@ ext = Extension("hiredis.hiredis",
                 sources=get_sources(),
                 extra_compile_args=get_compiler_args(),
                 extra_link_args=get_linker_args(),
-                libraries=get_libraries(),
-                include_dirs=["vendor"])
+                include_dirs=["/usr/local/include"],
+                library_dirs=["/usr/local/lib"],
+                libraries=["hiredis"])
 
 setup(
     name="hiredis",
