--- setup.py.orig	2015-04-14 07:23:17 UTC
+++ setup.py
@@ -45,6 +45,7 @@ ext_modules = [
             '-fno-strict-aliasing',
             '-Werror-implicit-function-declaration',
             '-Wfatal-errors',
+            '-I%%LOCALBASE%%/include/',
         ],
         libraries = ['lo'],
     )
@@ -63,12 +64,7 @@ setup(
         'scripts/send_osc.py',
         'scripts/dump_osc.py',
     ],
-    data_files = [
-        ('share/man/man1', [
-            'scripts/send_osc.1',
-            'scripts/dump_osc.1',
-        ]),
-    ],
+    data_files = [],
     cmdclass = cmdclass,
     ext_modules = ext_modules,
     **args
