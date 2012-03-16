--- gyp/common.gypi.orig	2012-03-16 10:48:02.138711974 +0900
+++ gyp/common.gypi	2012-03-16 10:59:55.917712287 +0900
@@ -43,7 +43,7 @@
     # warning_cflags will be shared with Mac and Linux.
     'warning_cflags': [
       '-Wall',
-      '-Werror',
+#      '-Werror',
       '-Wno-char-subscripts',
       '-Wno-sign-compare',
       '-Wno-deprecated-declarations',
@@ -593,6 +593,12 @@
           # <unordered_map> and <unordered_set>.
           '-Wno-deprecated',
         ],
+        'include_dirs': [
+          '@@LOCALBASE@@/include'
+        ],
+        'ldflags': [
+          '-L@@LOCALBASE@@/lib'
+        ],
         'link_settings': {
           'libraries': [
             '<@(linux_libs)',
