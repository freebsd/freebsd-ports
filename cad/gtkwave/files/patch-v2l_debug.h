--- src/helpers/v2l_debug.h.orig	Sat May 11 00:28:43 2002
+++ src/helpers/v2l_debug.h	Sat May 11 00:30:02 2002
@@ -79,14 +79,6 @@
  * memory leaks because of it.  you have been warned.
  */
 
-#ifndef __sun__
-#ifndef alloca
-#define alloca __alloca
-#endif
-#else
-#include <alloca.h>
-#endif
-
 #define wave_alloca alloca
 
 
