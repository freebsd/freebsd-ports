--- gyp/common.gypi.orig	2013-03-29 13:33:42.000000000 +0900
+++ gyp/common.gypi	2013-04-28 17:38:16.000000000 +0900
@@ -723,7 +723,9 @@
       ['OS=="linux"', {
         'defines': [
           'OS_LINUX',
+          'OS_FREEBSD',
           'MOZC_SERVER_DIRECTORY="<@(server_dir)"',
+          'LOCALBASE="<@(localbase)"',
         ],
         'cflags': [
           '<@(warning_cflags)',
@@ -735,6 +737,13 @@
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
           ['target_platform=="ChromeOS"', {
             'defines': [
