--- third_party/gyp/pylib/gyp/common.py.orig	2012-01-29 13:42:31.158806631 +0900
+++ third_party/gyp/pylib/gyp/common.py	2012-01-30 15:35:06.300889252 +0900
@@ -351,8 +351,10 @@
   flavors = {
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
