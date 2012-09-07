--- gyp/common.gypi.orig	2012-09-07 10:21:29.209021370 +0900
+++ gyp/common.gypi	2012-09-07 10:30:44.919021522 +0900
@@ -58,7 +58,7 @@
     # warning_cflags will be shared with Mac and Linux.
     'warning_cflags': [
       '-Wall',
-      '-Werror',
+#      '-Werror',
       '-Wno-char-subscripts',
       '-Wno-sign-compare',
       '-Wno-deprecated-declarations',
@@ -752,6 +752,12 @@
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
