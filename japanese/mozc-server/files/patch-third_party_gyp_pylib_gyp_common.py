--- third_party/gyp/pylib/gyp/common.py.orig	2012-05-29 15:36:59.734962050 +0900
+++ third_party/gyp/pylib/gyp/common.py	2012-05-01 12:46:18.154691389 +0900
@@ -353,8 +353,10 @@
     'win32': 'win',
     'darwin': 'mac',
     'sunos5': 'solaris',
-    'freebsd7': 'freebsd',
-    'freebsd8': 'freebsd',
+    'freebsd7': 'linux',
+    'freebsd8': 'linux',
+    'freebsd9': 'linux',
+    'freebsd10': 'linux',
   }
   flavor = flavors.get(sys.platform, 'linux')
   return params.get('flavor', flavor)
