--- node_modules/kerberos/binding.gyp.orig	2024-05-13 15:16:38 UTC
+++ node_modules/kerberos/binding.gyp
@@ -34,14 +34,17 @@
               'GCC_SYMBOLS_PRIVATE_EXTERN': 'YES', # -fvisibility=hidden
             }
         }],
-        ['OS=="mac" or OS=="linux"', {
+        ['OS=="mac" or OS=="linux" or OS=="freebsd"', {
           'sources': [
             'src/unix/base64.cc',
             'src/unix/kerberos_gss.cc',
             'src/unix/kerberos_unix.cc'
           ]
         }],
-        ['(OS=="mac" or OS=="linux") and (kerberos_use_rtld!="true")', {
+        ['(OS=="mac" or OS=="linux" or OS=="freebsd") and (kerberos_use_rtld!="true")', {
+          'include_dirs': [
+            '%%LOCALBASE%%/include'
+          ],
           'link_settings': {
             'libraries': [
               '-lkrb5',
@@ -58,7 +62,7 @@
             }]
           ]
         }],
-        ['(OS=="mac" or OS=="linux") and (kerberos_use_rtld=="true")', {
+        ['(OS=="mac" or OS=="linux" or OS=="freebsd") and (kerberos_use_rtld=="true")', {
           'defines': ['KERBEROS_USE_RTLD=1'],
           'link_settings': {
             'libraries': [
