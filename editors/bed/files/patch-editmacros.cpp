--- src/editmacros.cpp.orig	Mon Dec  8 10:34:23 2003
+++ src/editmacros.cpp	Mon Dec  8 10:35:00 2003
@@ -153,7 +153,7 @@
 #define	offwrite(handle,off,str, len) ((lseek(handle,off,SEEK_SET)==off)?write(handle,str,len)==len:0)
 #include "varmacro.h"
 #ifdef OLDGCCVARMACRO
-#define returnmessage(x...) {message( ## x);beep();erefresh();return -1;} VARMACRO
+#define returnmessage(x...) {message(  x);beep();erefresh();return -1;} VARMACRO
 #else
 #define returnmessage(...) {message(__VA_ARGS__);beep();erefresh();return -1;} 
 #endif
