--- gyp/common.gypi.org	2010-09-25 11:08:08.270335412 +0900
+++ gyp/common.gypi	2010-09-25 11:08:34.704344483 +0900
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
