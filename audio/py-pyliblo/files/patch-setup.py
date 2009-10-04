--- setup.py.orig	2009-10-04 19:12:34.000000000 +0800
+++ setup.py	2009-10-04 19:14:46.000000000 +0800
@@ -42,6 +42,7 @@
         extra_compile_args = [
             '-fno-strict-aliasing',
             '-Werror-implicit-function-declaration',
+	    '-I%%LOCALBASE%%/include/',
         ],
         libraries = ['lo']
     )
@@ -63,12 +64,7 @@
         'scripts/send_osc.py',
         'scripts/dump_osc.py',
     ],
-    data_files = [
-        ('share/man/man1', [
-            'scripts/send_osc.1',
-            'scripts/dump_osc.1',
-        ]),
-    ],
+
     cmdclass = cmdclass,
     ext_modules = ext_modules
 )
