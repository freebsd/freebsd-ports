--- setup.py.orig	2014-08-17 09:21:38 UTC
+++ setup.py
@@ -33,6 +33,8 @@ from distutils.core import setup, Extens
 
 _pcre = Extension('_pcre', ['src/pcremodule.c'],
                   libraries=['pcre'],
+                  include_dirs=['%%LOCALBASE%%/include'],
+                  library_dirs=['%%LOCALBASE%%/lib'],
                   extra_compile_args=['-fno-strict-aliasing'])
 
 
