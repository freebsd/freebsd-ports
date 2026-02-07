--- ./g_local.h.orig	Fri Jul 28 16:29:27 2006
+++ ./g_local.h	Fri Jul 28 16:33:09 2006
@@ -27,7 +27,7 @@
 #ifdef __sun__
 #define _isnan(a) (NaN((a)))
 #else
-#define _isnan(a) ((a)==NAN)
+#define _isnan(a) (isnan(a))
 #endif
 #endif
 
