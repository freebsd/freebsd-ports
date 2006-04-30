--- OOCocoa.h.orig	Thu Apr 27 14:16:30 2006
+++ OOCocoa.h	Thu Apr 27 15:14:04 2006
@@ -1,7 +1,7 @@
 // Import OpenStep main headers and define some Macisms and other compatibility stuff.
 
 #if defined(GNUSTEP) && !defined(OOLITE_SDL_MAC)
-#include <stdint.h>
+#include <inttypes.h>
 #define Boolean unsigned char
 #define Byte unsigned char
 #define true 1
