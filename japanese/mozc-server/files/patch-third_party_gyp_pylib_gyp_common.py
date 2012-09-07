--- third_party/gyp/pylib/gyp/common.py.orig	2012-09-07 10:21:29.147021135 +0900
+++ third_party/gyp/pylib/gyp/common.py	2012-09-07 10:30:44.711021503 +0900
@@ -362,8 +362,10 @@
     'win32': 'win',
     'darwin': 'mac',
     'sunos5': 'solaris',
-    'freebsd7': 'freebsd',
-    'freebsd8': 'freebsd',
+    'freebsd7': 'linux',
+    'freebsd8': 'linux',
+    'freebsd9': 'linux',
+    'freebsd10': 'linux',
     'freebsd9': 'freebsd',
   }
   flavor = flavors.get(sys.platform, 'linux')
