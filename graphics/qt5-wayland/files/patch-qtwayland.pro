--- qtwayland.pro.orig  2017-06-23 10:50:50 UTC
+++ qtwayland.pro
@@ -1,3 +1,4 @@
-requires(linux:!android)
+requires(!android)
+requires(linux|freebsd)
 requires(qtHaveModule(gui))
 load(qt_parts)
