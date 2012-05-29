--- gyp/common.gypi.orig	2012-05-29 15:37:00.311960872 +0900
+++ gyp/common.gypi	2012-05-29 16:04:45.995960165 +0900
@@ -46,7 +46,7 @@
     # warning_cflags will be shared with Mac and Linux.
     'warning_cflags': [
       '-Wall',
-      '-Werror',
+#      '-Werror',
       '-Wno-char-subscripts',
       '-Wno-sign-compare',
       '-Wno-deprecated-declarations',
@@ -730,6 +730,12 @@
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
           ['chromeos==1', {
             'defines': [
