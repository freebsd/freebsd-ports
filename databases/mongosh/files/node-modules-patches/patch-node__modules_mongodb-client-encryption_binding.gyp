--- node_modules/mongodb-client-encryption/binding.gyp.orig	2024-05-13 14:10:24 UTC
+++ node_modules/mongodb-client-encryption/binding.gyp
@@ -38,9 +38,14 @@
           }
       }],
       ['build_type=="dynamic"', {
+        'defines': [ 'NODE_API_EXPERIMENTAL_NOGC_ENV_OPT_OUT' ],
+        'include_dirs': [
+          '/usr/include',
+          '/usr/local/include'
+        ],
         'link_settings': {
           'libraries': [
-            '-lmongocrypt'
+            '-L/usr/local/lib -lmongocrypt'
           ]
         }
       }],
@@ -48,13 +53,12 @@
         'conditions': [
           ['OS!="win"', {
             'include_dirs': [
-              '<(module_root_dir)/deps/include'
+              '/usr/include',
+              '/usr/local/include'
             ],
             'link_settings': {
               'libraries': [
-                '<(module_root_dir)/deps/lib/libmongocrypt-static.a',
-                '<(module_root_dir)/deps/lib/libkms_message-static.a',
-                '<(module_root_dir)/deps/lib/libbson-static-for-libmongocrypt.a'
+                '-L/usr/local/lib -lmongocrypt'
               ]
             }
           }],
