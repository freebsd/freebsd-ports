--- gyp/common.gypi.orig	2014-08-31 03:36:19.000000000 +0900
+++ gyp/common.gypi	2014-08-31 03:46:27.000000000 +0900
@@ -759,6 +759,8 @@
       ['OS=="linux"', {
         'defines': [
           'OS_LINUX',
+          'OS_FREEBSD',
+          'LOCALBASE="<@(localbase)"',
         ],
         'cflags': [
           '<@(warning_cflags)',
@@ -770,6 +772,13 @@
           # <unordered_map> and <unordered_set>.
           '-Wno-deprecated',
         ],
+        'include_dirs': [
+          '<@(include_dirs)'
+        ],
+        'ldflags': [
+          '<@(ldflags)',
+	  '-fstack-protector',
+        ],
         'conditions': [
           ['target_platform!="NaCl"', {
             'cflags': [
