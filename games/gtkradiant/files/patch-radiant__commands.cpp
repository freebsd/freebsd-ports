--- ./radiant/commands.cpp.orig	Fri Feb 10 19:01:20 2006
+++ ./radiant/commands.cpp	Thu Mar 16 16:09:46 2006
@@ -128,7 +128,7 @@
 #include <gdk/gdkkeysyms.h>
 #include <ctype.h>
 
-#ifdef __APPLE__
+#if defined(__APPLE__) || defined(__FreeBSD__)
 #define __toascii(c)    ((c) & 0x7f)
 #endif
 
