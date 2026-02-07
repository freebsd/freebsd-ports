--- ucon64.c.orig	2019-05-29 15:54:58 UTC
+++ ucon64.c
@@ -2081,7 +2081,7 @@ ucon64_usage (int argc, char *argv[], int view)
 #elif   defined __APPLE__                       // Mac OS X actually
     "libdiscmage.dylib";
 #elif   defined __unix__ || defined __BEOS__
-    "libdiscmage.so";
+    "%%PREFIX%%/lib/libdiscmage.so";
 #else
     "library";
 #endif
