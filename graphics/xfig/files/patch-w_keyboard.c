--- w_keyboard.c.orig	Tue Nov  9 13:10:22 2004
+++ w_keyboard.c	Mon Apr  2 22:29:31 2007
@@ -18,7 +18,9 @@
 
 #include <sys/types.h>
 #include <regex.h>
+#ifndef __FreeBSD__
 #include <alloca.h>
+#endif
 #include <string.h>
 #include <math.h>
 
@@ -35,6 +37,9 @@
 
 #if defined(__CYGWIN__)
 #define REG_NOERROR REG_OKAY
+#endif
+#if defined(__FreeBSD__) && !defined(REG_NOERROR)
+#define REG_NOERROR 0
 #endif
 
 Boolean keyboard_input_available = False;
