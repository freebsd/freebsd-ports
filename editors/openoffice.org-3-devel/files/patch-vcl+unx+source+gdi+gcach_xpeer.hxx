--- ../vcl/unx/source/gdi/gcach_xpeer.hxx.orig	Tue Mar 11 16:32:14 2003
+++ ../vcl/unx/source/gdi/gcach_xpeer.hxx	Tue Mar 11 16:32:19 2003
@@ -65,6 +65,8 @@
 #include <glyphcache.hxx>
 
 #define Region XLIB_Region
+typedef unsigned long CARD32;
+#define Cursor CARD32
 #include <X11/extensions/Xrender.h>
 #undef Region
 
