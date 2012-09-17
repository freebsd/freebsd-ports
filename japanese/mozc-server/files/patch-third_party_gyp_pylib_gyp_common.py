--- third_party/gyp/pylib/gyp/common.py.orig	2012-09-07 10:21:29.147021135 +0900
+++ third_party/gyp/pylib/gyp/common.py	2012-09-17 17:14:43.781601968 +0900
@@ -362,9 +362,11 @@
     'win32': 'win',
     'darwin': 'mac',
     'sunos5': 'solaris',
-    'freebsd7': 'freebsd',
-    'freebsd8': 'freebsd',
-    'freebsd9': 'freebsd',
+    'freebsd7': 'linux',
+    'freebsd8': 'linux',
+    'freebsd9': 'linux',
+    'freebsd10': 'linux',
+    'freebsd11': 'linux',
   }
   flavor = flavors.get(sys.platform, 'linux')
   return params.get('flavor', flavor)
