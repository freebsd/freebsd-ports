--- plugins/organic/organic.cpp.orig	2015-03-08 02:47:14 UTC
+++ plugins/organic/organic.cpp
@@ -41,6 +41,9 @@
 
 #include "embed.cpp"
 
+#if __FreeBSD_version <= 704100 || (__FreeBSD_version >= 800000 && __FreeBSD_version < 802502) || (__FreeBSD_version >= 900000 && __FreeBSD_version < 900027)
+#define log2f(x) (logf(x) / logf(2))
+#endif
 
 
 
