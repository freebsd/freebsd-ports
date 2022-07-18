--- setup.py.orig	2022-07-12 00:42:43 UTC
+++ setup.py
@@ -315,7 +315,7 @@ def awscrt_ext():
 
     if distutils.ccompiler.get_default_compiler() != 'msvc':
         extra_compile_args += ['-Wextra', '-Werror', '-Wno-strict-aliasing', '-std=gnu99']
-        extra_link_args += ['-Wl,-fatal_warnings']
+        extra_link_args += ['-Wl,-fatal-warnings']
 
     return setuptools.Extension(
         '_awscrt',
