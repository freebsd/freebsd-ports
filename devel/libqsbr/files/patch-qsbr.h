--- qsbr.h.orig	2023-10-25 22:40:12 UTC
+++ qsbr.h
@@ -13,7 +13,11 @@
 
 struct qsbr;
 typedef struct qsbr qsbr_t;
+#if defined(__LONG_WIDTH__) && __LONG_WIDTH < 64
+typedef unsigned long long qsbr_epoch_t;
+#else
 typedef unsigned long qsbr_epoch_t;
+#endif
 
 __BEGIN_DECLS
 
