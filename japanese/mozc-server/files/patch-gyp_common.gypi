--- gyp/common.gypi.orig	2011-12-04 16:22:26.257607334 +0900
+++ gyp/common.gypi	2011-12-12 22:34:30.005072813 +0900
@@ -50,7 +50,7 @@
     # warning_cflags will be shared with Mac and Linux.
     'warning_cflags': [
       '-Wall',
-      '-Werror',
+#      '-Werror',
       '-Wno-char-subscripts',
       '-Wno-sign-compare',
       '-Wno-deprecated-declarations',
@@ -512,6 +512,12 @@
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
