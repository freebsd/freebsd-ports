--- /usr/ports/devel/cocktail/work/cocktail-9309//./reuse/m2c/Pack.h	Tue Feb 15 14:26:56 1994
+++ ./reuse/m2c/Pack.h	Thu Aug  5 18:49:34 2004
@@ -1,5 +1,9 @@
 #define DEFINITION_Pack
 
+#ifndef DEFINITION_SYSTEM_
+#include "SYSTEM_.h"
+#endif
+
 #ifndef DEFINITION_IO
 #include "IO.h"
 #endif
@@ -16,4 +20,4 @@
 extern void Pack_UnpackCard ARGS((Pack_UnpackCardHandler handler, CHAR string[], LONGCARD , CARDINAL count));
 extern void Pack_Unpack ARGS((Pack_UnpackCardHandler handler, CHAR string[], LONGCARD , CARDINAL count));
 extern void Pack_UnpackInt ARGS((Pack_UnpackIntHandler handler, CHAR string[], LONGCARD , CARDINAL count));
-extern void BEGIN_Pack();
+extern void BEGIN_Pack(NOARGS);
