--- build.py.orig	2016-01-24 18:24:05 UTC
+++ build.py
@@ -56,6 +56,13 @@ openssl_search_paths = [{
     "-I/opt/local/include",
     "-L/opt/local/lib"
   ]
+}, {
+  "name": "freebsd",
+  "header": "/usr/local/include/openssl/opensslv.h",
+  "flags": [
+    "-I/usr/local/include",
+    "-L/usr/local/lib"
+  ]
 }]
 
 # check if path points to an executable
