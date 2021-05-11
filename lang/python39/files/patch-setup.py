--- setup.py.orig	2021-02-17 17:43:29 UTC
+++ setup.py
@@ -2196,7 +2196,7 @@ class PyBuildExt(build_ext):
         undef_macros = []
         if '--with-system-libmpdec' in sysconfig.get_config_var("CONFIG_ARGS"):
             include_dirs = []
-            libraries = [':libmpdec.so.2']
+            libraries = ['mpdec']
             sources = ['_decimal/_decimal.c']
             depends = ['_decimal/docstrings.h']
         else:
