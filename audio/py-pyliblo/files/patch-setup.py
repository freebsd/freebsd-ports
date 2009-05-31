--- setup.py.orig	2009-06-01 03:12:01.000000000 +0800
+++ setup.py	2009-06-01 03:14:23.000000000 +0800
@@ -34,7 +34,7 @@
 ext_modules = [
     Extension('liblo',
               [with_pyrex and 'src/liblo.pyx' or 'src/liblo.c'],
-              extra_compile_args = ['-fno-strict-aliasing'],
+              extra_compile_args = ['-fno-strict-aliasing','-I%%LOCALBASE%%/include/'],
               libraries = ['lo'])
 ]
 
@@ -54,12 +54,12 @@
         'scripts/send_osc.py',
         'scripts/dump_osc.py',
     ],
-    data_files = [
-        ('share/man/man1', [
-            'scripts/send_osc.1',
-            'scripts/dump_osc.1',
-        ]),
-    ],
+#    data_files = [
+#        ('share/man/man1', [
+#            'scripts/send_osc.1',
+#            'scripts/dump_osc.1',
+#        ]),
+#    ],
     cmdclass = cmdclass,
     ext_modules = ext_modules
 )
