--- src/gyp/common.gypi.org	2010-05-23 14:03:58.827531279 +0900
+++ src/gyp/common.gypi	2010-05-23 13:58:38.441081884 +0900
@@ -420,6 +420,8 @@
           '-lssl',
           '-lz',
         ],
+        'include_dirs': [ '@@LOCALBASE@@/include' ],
+        'ldflags': [ '-L@@LOCALBASE@@/lib' ],
         'conditions': [
           ['chromeos==1', {
             'defines': [
