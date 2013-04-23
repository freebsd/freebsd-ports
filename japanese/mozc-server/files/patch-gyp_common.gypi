--- gyp/common.gypi.orig	2013-04-21 03:48:45.395416165 +0900
+++ gyp/common.gypi	2013-04-21 08:31:10.191270448 +0900
@@ -58,7 +58,7 @@
     # warning_cflags will be shared with Mac and Linux.
     'warning_cflags': [
       '-Wall',
-      '-Werror',
+#      '-Werror',
       '-Wno-char-subscripts',
       '-Wno-sign-compare',
       '-Wno-deprecated-declarations',
@@ -194,7 +194,7 @@
     # - http://code.google.com/p/protobuf/issues/detail?id=128
     # - http://code.google.com/p/protobuf/issues/detail?id=370
     # for the background information.
-    'use_libprotobuf%': 0,
+    'use_libprotobuf%': 1,
 
     # use_libzinnia represents if zinnia library is used or not.
     # This option is only for Linux.
@@ -735,6 +735,12 @@
           # <unordered_map> and <unordered_set>.
           '-Wno-deprecated',
         ],
+        'include_dirs': [
+          '@@LOCALBASE@@/include'
+        ],
+        'ldflags': [
+          '-L@@LOCALBASE@@/lib'
+        ],
         'conditions': [
           ['target_platform=="ChromeOS"', {
             'defines': [
