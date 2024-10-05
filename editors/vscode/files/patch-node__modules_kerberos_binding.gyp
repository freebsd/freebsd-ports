--- node_modules/kerberos/binding.gyp.orig	2024-09-09 06:45:52 UTC
+++ node_modules/kerberos/binding.gyp
@@ -54,7 +54,7 @@
             ]
           }
         }],
-        ['OS=="mac" or OS=="linux"', {
+        ['OS=="mac" or OS=="linux" or OS=="freebsd"', {
           'sources': [
             'src/unix/base64.cc',
             'src/unix/kerberos_gss.cc',
