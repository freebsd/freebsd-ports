--- gyp/common.gypi.org	2010-06-17 15:59:08.053080522 +0900
+++ gyp/common.gypi	2010-06-26 14:48:00.645671527 +0900
@@ -371,6 +371,12 @@
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
           ['chromeos==1', {
             'defines': [
