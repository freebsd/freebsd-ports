--- gyp/common.gypi.orig	2011-12-24 13:17:13.115092509 +0900
+++ gyp/common.gypi	2011-12-24 13:35:51.371092696 +0900
@@ -50,7 +50,7 @@
     # warning_cflags will be shared with Mac and Linux.
     'warning_cflags': [
       '-Wall',
-      '-Werror',
+#      '-Werror',
       '-Wno-char-subscripts',
       '-Wno-sign-compare',
       '-Wno-deprecated-declarations',
@@ -528,6 +528,12 @@
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
