--- gyp/common.gypi.orig	2012-05-01 12:21:08.159691563 +0900
+++ gyp/common.gypi	2012-05-01 12:46:18.406692000 +0900
@@ -50,7 +50,7 @@
     # warning_cflags will be shared with Mac and Linux.
     'warning_cflags': [
       '-Wall',
-      '-Werror',
+#      '-Werror',
       '-Wno-char-subscripts',
       '-Wno-sign-compare',
       '-Wno-deprecated-declarations',
@@ -720,6 +720,12 @@
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
