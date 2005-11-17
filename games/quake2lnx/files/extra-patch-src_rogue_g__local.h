--- src/rogue/g_local.h.orig	Mon Nov 30 17:53:20 1998
+++ src/rogue/g_local.h	Tue Sep 27 20:20:27 2005
@@ -22,7 +22,6 @@
 //==================================================================
 
 #ifndef _WIN32
-#include <nan.h>
 #define min(a,b) ((a) < (b) ? (a) : (b))
 #define max(a,b) ((a) > (b) ? (a) : (b))
 #ifdef __sun__
