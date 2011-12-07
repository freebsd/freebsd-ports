--- plugins/organic/organic.cpp	2011-07-02 13:14:01.000000000 +0000
+++ plugins/organic/organic.cpp.new	2011-09-28 09:55:59.000000000 +0000
@@ -41,6 +41,9 @@
 
 #include "embed.cpp"
 
+#if __FreeBSD_version <= 704100 || (__FreeBSD_version >= 800000 && __FreeBSD_version < 802502) || (__FreeBSD_version >= 900000 && __FreeBSD_version < 900027)
+#define log2f(x) (logf(x) / logf(2))
+#endif
 
 extern "C"
 {
