--- gyp/common.gypi.org	2010-09-18 12:48:37.180713244 +0900
+++ gyp/common.gypi	2010-09-18 12:49:57.723919434 +0900
@@ -437,6 +437,12 @@
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
