--- src/read_cache.c.bak	Thu Jul  4 02:59:56 2002
+++ src/read_cache.c	Thu Jul  4 02:59:56 2002
@@ -83,7 +83,7 @@
 #define _MT_TRACE 1
 
 #if _MT_TRACE
-#define dprintf(fmt, args...) fprintf(stderr, "%s: " fmt,  __FUNCTION__, ##args);
+#define dprintf(fmt, args...) fprintf(stderr, "%s: "fmt, __FUNCTION__ ,## args)
 #else
 #define dprintf(fmt, args...) /* Nowt */
 #endif
