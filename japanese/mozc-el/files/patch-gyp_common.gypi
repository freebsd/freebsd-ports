--- gyp/common.gypi.org	2010-11-06 10:50:16.532187538 +0900
+++ gyp/common.gypi	2010-11-06 10:50:37.769189168 +0900
@@ -436,6 +436,12 @@
           '-lz',
           '<@(extra_linux_libs)',
         ],
+        'include_dirs': [
+          '@@LOCALBASE@@/include'
+        ],
+        'ldflags': [
+          '-L@@LOCALBASE@@/lib'
+        ],
         'conditions': [
           ['use_libgtest==0', {
             'include_dirs': [
