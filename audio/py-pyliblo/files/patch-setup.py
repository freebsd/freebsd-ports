--- setup.py.orig	2014-09-17 12:36:01.069734246 +0200
+++ setup.py	2014-09-17 12:36:49.484953374 +0200
@@ -45,6 +45,7 @@
             '-fno-strict-aliasing',
             '-Werror-implicit-function-declaration',
             '-Wfatal-errors',
+            '-I%%LOCALBASE%%/include/',
         ],
         libraries = ['lo']
     )
@@ -66,12 +67,7 @@
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
     ext_modules = ext_modules
 )
