--- node_modules/mongodb-client-encryption/binding.gyp.orig	2024-11-15 19:23:54 UTC
+++ node_modules/mongodb-client-encryption/binding.gyp
@@ -42,7 +42,11 @@
           }
       }],
       ['libmongocrypt_link_type=="dynamic"', {
-        'link_settings': { 'libraries': ['-lmongocrypt'] }
+        'include_dirs': [
+          '/usr/include',
+          '%%LOCALBASE%%/include'
+        ],
+        'link_settings': { 'libraries': ['-L%%LOCALBASE%%/lib -lmongocrypt'] }
       }],
       ['libmongocrypt_link_type=="static"', {
         'conditions': [
