--- io_lib/c_range_coder.h.orig	2018-10-18 16:44:55 UTC
+++ io_lib/c_range_coder.h
@@ -14,8 +14,6 @@
 #define  DO(n)	   int _;for (_=0; _<n; _++)
 #define  TOP	   (1<<24)
 
-typedef unsigned char uc;
-
 typedef struct {
     uint64_t low;
     uint32_t range, code;
