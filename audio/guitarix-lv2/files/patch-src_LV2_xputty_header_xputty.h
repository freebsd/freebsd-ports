--- src/LV2/xputty/header/xputty.h.orig	2025-03-26 05:38:17 UTC
+++ src/LV2/xputty/header/xputty.h
@@ -34,7 +34,7 @@
 #include <math.h>
 #include <cairo.h>
 #include "xputty-mswin.h" // no ifdef (waf dependency check)
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
 #include <cairo-xlib.h>
 #include <X11/Xutil.h>
 #include <X11/keysym.h>
