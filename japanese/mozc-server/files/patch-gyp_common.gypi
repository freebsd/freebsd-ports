--- gyp/common.gypi.orig	2012-01-29 13:42:31.215806054 +0900
+++ gyp/common.gypi	2012-01-29 13:49:19.328805472 +0900
@@ -50,7 +50,7 @@
     # warning_cflags will be shared with Mac and Linux.
     'warning_cflags': [
       '-Wall',
-      '-Werror',
+#      '-Werror',
       '-Wno-char-subscripts',
       '-Wno-sign-compare',
       '-Wno-deprecated-declarations',
@@ -568,6 +568,12 @@
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
