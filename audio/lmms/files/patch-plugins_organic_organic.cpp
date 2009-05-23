--- plugins/organic/organic.cpp.orig	2009-02-24 07:34:26.000000000 +0900
+++ plugins/organic/organic.cpp	2009-04-09 03:38:36.000000000 +0900
@@ -42,6 +42,9 @@
 #undef SINGLE_SOURCE_COMPILE
 #include "embed.cpp"
 
+#if defined(__FreeBSD__)
+#define log2f(x) (logf((x)) / logf(2))
+#endif
 
 extern "C"
 {
