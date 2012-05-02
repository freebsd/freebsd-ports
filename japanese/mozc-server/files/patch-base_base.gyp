--- base/base.gyp.orig	2012-04-26 15:05:41.000000000 +0900
+++ base/base.gyp	2012-05-02 00:42:12.000000000 +0900
@@ -228,20 +228,20 @@
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
