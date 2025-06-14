--- remote/node_modules/kerberos/binding.gyp.orig	2025-06-12 22:38:39 UTC
+++ remote/node_modules/kerberos/binding.gyp
@@ -54,14 +54,14 @@
             ]
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
           'link_settings': {
             'libraries': [
               '-lkrb5',
@@ -78,7 +78,7 @@
             }]
           ]
         }],
-        ['(OS=="mac" or OS=="linux") and (kerberos_use_rtld=="true")', {
+        ['(OS=="mac" or OS=="linux" or OS=="freebsd") and (kerberos_use_rtld=="true")', {
           'defines': ['KERBEROS_USE_RTLD=1'],
           'link_settings': {
             'libraries': [
