--- gyp/common.gypi.orig	2012-04-02 08:17:52.785727643 +0900
+++ gyp/common.gypi	2012-04-02 08:32:43.630727845 +0900
@@ -53,7 +53,7 @@
     # warning_cflags will be shared with Mac and Linux.
     'warning_cflags': [
       '-Wall',
-      '-Werror',
+#      '-Werror',
       '-Wno-char-subscripts',
       '-Wno-sign-compare',
       '-Wno-deprecated-declarations',
@@ -717,6 +717,12 @@
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
           ['target_platform!="Android"', {
             'link_settings': {
