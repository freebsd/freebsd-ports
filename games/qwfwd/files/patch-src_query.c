--- src/query.c.orig	2025-02-21 06:10:33 UTC
+++ src/query.c
@@ -21,7 +21,7 @@
 
 #define MAX_MASTERS 8 // size for masters fixed size array, I am lazy
 
-#define MAX_SERVERS 512 // we will not add more than that servers to our list, just for some sanity
+#define MAX_SERVERS 4096 // we will not add more than that servers to our list, just for some sanity
 
 #define MAX_SV_FILTERS 16 // how much servers we can filter with masters_filter_servers, can be increased widely.
 #define QW_DEFAULT_SV_FILTER "127.0.0.1" // some masters provide unusable servers, filter them.
