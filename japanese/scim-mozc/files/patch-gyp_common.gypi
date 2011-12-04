--- gyp/common.gypi.orig	2011-12-04 16:22:26.257607334 +0900
+++ gyp/common.gypi	2011-12-04 16:46:48.756621873 +0900
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
