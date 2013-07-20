--- gyp/common.gypi.orig	2013-07-17 11:38:04.000000000 +0900
+++ gyp/common.gypi	2013-07-19 22:51:13.000000000 +0900
@@ -749,6 +749,8 @@
       ['OS=="linux"', {
         'defines': [
           'OS_LINUX',
+          'OS_FREEBSD',
+          'LOCALBASE="<@(localbase)"',
         ],
         'cflags': [
           '<@(warning_cflags)',
@@ -760,6 +762,13 @@
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
@@ -774,12 +783,10 @@
               '-Wno-covered-switch-default',
               '-Wno-unnamed-type-template-args',
               '-Wno-c++11-narrowing',
-              '-std=gnu++0x',
             ],
           }],
           ['clang==0 and target_platform!="Windows"', {
             'cflags_cc': [
-              '-std=gnu++0x',
             ],
             'defines': [
               'GTEST_LANG_CXX11=0',
