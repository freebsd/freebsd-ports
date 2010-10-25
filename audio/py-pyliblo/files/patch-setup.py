--- setup.py.orig	2010-10-25 15:47:52.000000000 +0800
+++ setup.py	2010-10-25 15:54:41.000000000 +0800
@@ -39,6 +39,7 @@
             '-fno-strict-aliasing',
             '-Werror-implicit-function-declaration',
             '-Wfatal-errors',
+	    '-I%%LOCALBASE%%/include/',
         ],
         libraries = ['lo']
     )
@@ -53,12 +54,7 @@
         'scripts/send_osc.py',
         'scripts/dump_osc.py',
     ]
-    data_files = [
-        ('share/man/man1', [
-            'scripts/send_osc.1',
-            'scripts/dump_osc.1',
-        ]),
-    ]
+    data_files = []
 else:
     # doesn't work with Python 3.x yet
     scripts = []
