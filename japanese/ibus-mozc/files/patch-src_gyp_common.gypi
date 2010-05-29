--- src/gyp/common.gypi.org	2010-05-29 11:05:15.815250973 +0900
+++ src/gyp/common.gypi	2010-05-29 11:30:52.119608091 +0900
@@ -420,6 +420,8 @@
           '-lssl',
           '-lz',
         ],
+        'include_dirs': [ '@@LOCALBASE@@/include' ],
+        'ldflags': [ '-L@@LOCALBASE@@/lib' ],
         'conditions': [
           ['chromeos==1', {
             'defines': [
