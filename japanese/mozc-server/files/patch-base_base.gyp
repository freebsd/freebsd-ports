--- base/base.gyp.orig	2013-04-21 03:48:45.178270244 +0900
+++ base/base.gyp	2013-04-21 04:16:38.943269499 +0900
@@ -265,20 +265,20 @@
         ['OS=="linux" and target_platform!="Android" and '
          'not (target_platform=="NaCl" and _toolset=="target")', {
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
