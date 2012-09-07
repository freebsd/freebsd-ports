--- base/base.gyp.orig	2012-09-07 10:21:29.099021913 +0900
+++ base/base.gyp	2012-09-07 10:30:46.575021640 +0900
@@ -262,20 +262,20 @@
         }],
         ['OS=="linux" and target_platform!="Android"', {
           'cflags': [
-            '<!@(<(pkg_config_command) --cflags-only-other openssl)',
+            '%%OPENSSL_CFLAGS%%',
           ],
           'defines': [
             'HAVE_OPENSSL=1',
           ],
           'include_dirs': [
-            '<!@(<(pkg_config_command) --cflags-only-I openssl)',
+            '-I%%OPENSSLINC%%/openssl',
           ],
           'link_settings': {
             'ldflags': [
-              '<!@(<(pkg_config_command) --libs-only-L openssl)',
+              '%%OPENSSL_LDFLAGS%% -L%%OPENSSLLIB%%',
             ],
             'libraries': [
-              '<!@(<(pkg_config_command) --libs-only-l openssl)',
+              '-lssl',
             ],
           },
         }],
