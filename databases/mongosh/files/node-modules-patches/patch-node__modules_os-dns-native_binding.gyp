--- node_modules/os-dns-native/binding.gyp.orig	2024-05-13 16:56:54 UTC
+++ node_modules/os-dns-native/binding.gyp
@@ -19,10 +19,6 @@
         "link_settings": {
           "libraries": ["-ldnsapi"]
         }
-      }, {
-        "link_settings": {
-          "libraries": ["-lresolv"]
-        }
       }]
     ]
   }]
