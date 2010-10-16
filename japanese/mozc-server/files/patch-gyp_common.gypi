--- gyp/common.gypi.org	2010-10-16 12:00:39.281175157 +0900
+++ gyp/common.gypi	2010-10-16 12:01:01.287193240 +0900
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
