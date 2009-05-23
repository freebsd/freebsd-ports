--- plugins/sf2_player/sf2_player.cpp.orig	2009-02-24 07:34:26.000000000 +0900
+++ plugins/sf2_player/sf2_player.cpp	2009-04-09 05:11:15.000000000 +0900
@@ -45,6 +45,9 @@
 #undef SINGLE_SOURCE_COMPILE
 #include "embed.cpp"
 
+#if defined(__FreeBSD__)
+#define log2(x) (log((x)) / log(2))
+#endif
 
 extern "C"
 {
