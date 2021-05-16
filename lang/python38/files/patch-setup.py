--- setup.py.orig	2021-05-03 09:47:56 UTC
+++ setup.py
@@ -2051,7 +2051,7 @@ class PyBuildExt(build_ext):
         undef_macros = []
         if '--with-system-libmpdec' in sysconfig.get_config_var("CONFIG_ARGS"):
             include_dirs = []
-            libraries = [':libmpdec.so.2']
+            libraries = ['mpdec']
             sources = ['_decimal/_decimal.c']
             depends = ['_decimal/docstrings.h']
         else:
