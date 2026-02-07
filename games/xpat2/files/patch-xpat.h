--- xpat.h.orig
+++ xpat.h
@@ -51,6 +51,8 @@
 #define EXIT_FAILURE (-1)
 #endif
 
+#define MAXXPMDIRLEN	100	/* pathname length including trailing zero */
+
 #ifndef max
 #define max(a, b)     ((a) > (b) ? (a) : (b))
 #define min(a, b)     ((a) < (b) ? (a) : (b))
