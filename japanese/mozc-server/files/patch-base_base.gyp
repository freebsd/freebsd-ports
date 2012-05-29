--- base/base.gyp.orig	2012-05-29 15:36:59.656961284 +0900
+++ base/base.gyp	2012-05-29 16:04:46.528961427 +0900
@@ -237,20 +237,20 @@
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
