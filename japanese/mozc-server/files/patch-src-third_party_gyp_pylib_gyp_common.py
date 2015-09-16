--- src/third_party/gyp/pylib/gyp/common.py.orig	2013-04-21 03:48:44.556270889 +0900
+++ src/third_party/gyp/pylib/gyp/common.py	2013-04-21 04:16:32.525269583 +0900
@@ -382,6 +382,11 @@
     'cygwin': 'win',
     'win32': 'win',
     'darwin': 'mac',
+    'freebsd7': 'linux',
+    'freebsd8': 'linux',
+    'freebsd9': 'linux',
+    'freebsd10': 'linux',
+    'freebsd11': 'linux'
   }
 
   if 'flavor' in params:
