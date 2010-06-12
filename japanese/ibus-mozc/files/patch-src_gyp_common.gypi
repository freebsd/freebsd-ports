--- gyp/common.gypi.org	2010-06-11 18:00:39.000000000 +0900
+++ gyp/common.gypi	2010-06-12 10:06:52.655552554 +0900
@@ -420,6 +420,8 @@
           '-lssl',
           '-lz',
         ],
+        'include_dirs': [ '@@LOCALBASE@@/include' ],
+        'ldflags': [ '-L@@LOCALBASE@@/lib' ],
         'conditions': [
           ['chromeos==1', {
             'defines': [
