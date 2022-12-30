--- setup.py.orig	2022-11-09 18:39:08 UTC
+++ setup.py
@@ -320,7 +320,7 @@ def awscrt_ext():
             # a proper MacOS Universal2 binary. The linker warns us about this,
             # but WHATEVER. Building everything twice (x86_64 and arm64) takes too long.
             if not is_macos_universal2():
-                extra_link_args += ['-Wl,-fatal_warnings']
+                extra_link_args += ['-Wl,-fatal-warnings']
 
     return setuptools.Extension(
         '_awscrt',
