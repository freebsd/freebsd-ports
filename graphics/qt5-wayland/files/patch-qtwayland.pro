--- qtwayland.pro.orig	2022-06-20 20:17:21 UTC
+++ qtwayland.pro
@@ -1,3 +1,4 @@
-requires(linux:!android|macos|qnx)
+requires(!android)
+requires(linux|freebsd)
 requires(qtHaveModule(gui))
 load(qt_parts)
