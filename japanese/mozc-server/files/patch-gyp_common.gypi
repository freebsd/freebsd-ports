--- gyp/common.gypi.org	2010-09-03 11:27:13.818109921 +0900
+++ gyp/common.gypi	2010-09-03 11:28:44.023549160 +0900
@@ -397,6 +397,12 @@
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
