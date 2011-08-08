--- gyp/common.gypi.orig	2011-07-19 14:42:19.000000000 +0900
+++ gyp/common.gypi	2011-07-30 12:56:54.000000000 +0900
@@ -447,7 +447,6 @@
         'cflags': [
           '<@(gcc_cflags)',
           '<@(warning_cflags)',
-          '-Wno-array-bounds',  # Probably GCC's bug 43949 causes trouble.
           '-fPIC',
           '-fno-exceptions',
         ],
@@ -456,6 +455,12 @@
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
           ['use_libgtest==0', {
             'include_dirs': [
