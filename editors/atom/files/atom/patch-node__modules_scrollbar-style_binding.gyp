--- node_modules/scrollbar-style/binding.gyp.orig	2015-01-28 01:01:40 UTC
+++ node_modules/scrollbar-style/binding.gyp
@@ -33,11 +33,11 @@
             4996,  # function was declared deprecated
           ],
         }],  # OS=="win"
-        ['OS=="linux"', {
+        ['OS=="linux" or OS=="freebsd"', {
           "sources": [
             "src/scrollbar-style-observer-non-mac.cc",
           ],
-        }],  # OS=="linux"
+        }],  # OS=="linux" or OS=="freebsd"
       ]
     }
   ]
