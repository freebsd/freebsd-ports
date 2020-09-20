--- src/define.h.orig	2006-07-12 17:20:12 UTC
+++ src/define.h
@@ -194,3 +194,11 @@
 #define FLAG(x)		(*((char *)&flag##x))
 
 #define VECFLAG(x)	(*((char *)flag##x))
+
+#ifdef IN_MAIN
+#define EXTERN
+#warning IN_MAIN
+#else
+#define EXTERN extern
+#warning NOT_IN_MAIN
+#endif
