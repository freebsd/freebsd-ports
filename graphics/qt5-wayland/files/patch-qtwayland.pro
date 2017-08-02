--- qtwayland.pro.orig	2016-10-28 06:24:31 UTC
+++ qtwayland.pro
@@ -1,4 +1,5 @@
-requires(linux:!android)
+requires(!android)
+requires(linux|freebsd)
 
 load(configure)
 qtCompileTest(wayland)
