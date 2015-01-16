--- src/1mem/mem.cc.orig	2015-01-13 21:18:27.778765410 +0800
+++ src/1mem/mem.cc	2015-01-13 21:19:17.118392234 +0800
@@ -67,6 +67,8 @@
   // TODO
 #elif __APPLE__
   // TODO
+#elif __FreeBSD__
+  // TODO
 #elif __GNUC__
   ::malloc_trim(File::get_granularity());
 #endif
