--- setup.py.orig	2023-07-31 16:01:19 UTC
+++ setup.py
@@ -79,7 +79,7 @@ ext_module = setuptools.Extension(
     sources=['_re2.cc'],
     include_dirs=list(include_dirs()),
     libraries=['re2'],
-    extra_compile_args=['-fvisibility=hidden'],
+    extra_compile_args=['--std=c++17', '-fvisibility=hidden'],
 )
 
 setuptools.setup(
