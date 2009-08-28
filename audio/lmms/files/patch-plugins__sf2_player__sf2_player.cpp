--- plugins/sf2_player/sf2_player.cpp.orig	2009-08-12 01:52:18.000000000 +0900
+++ plugins/sf2_player/sf2_player.cpp	2009-08-26 04:36:42.000000000 +0900
@@ -45,6 +45,9 @@
 
 #include "embed.cpp"
 
+#if defined(__FreeBSD__)
+#define log2(x) (log((x)) / log(2))
+#endif
 
 extern "C"
 {
