--- setup.py.orig	2009-11-01 08:44:12.000000000 +0800
+++ setup.py	2011-08-05 16:18:06.000000000 +0800
@@ -11,13 +11,13 @@
     pass
 
 sane = Extension('_sane',
-                 include_dirs = [PIL_IMAGING_DIR],
+                 include_dirs = [PIL_IMAGING_DIR, '/usr/local/include'],
                  libraries = ['sane'],
-                 library_dirs = [PIL_IMAGING_DIR],
+                 library_dirs = [PIL_IMAGING_DIR, '/usr/local/lib'],
                  define_macros = defs,
                  sources = ['_sane.c'])
 
-setup (name = 'pysane',
+setup (name = 'sane',
        version = '2.0',
        description = 'This is the pysane package',
        py_modules = ['sane'],
