--- configure.py.orig	2012-06-26 19:09:41.000000000 +0200
+++ configure.py	2012-06-26 19:09:54.000000000 +0200
@@ -117,7 +117,7 @@
         cflags += ['/Ox', '/DNDEBUG', '/GL']
         ldflags += ['/LTCG', '/OPT:REF', '/OPT:ICF']
 else:
-    cflags = ['-g', '-Wall', '-Wextra',
+    cflags = ['-Wall', '-Wextra',
               '-Wno-deprecated',
               '-Wno-unused-parameter',
               '-fno-rtti',
