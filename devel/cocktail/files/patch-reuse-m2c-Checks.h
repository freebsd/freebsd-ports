--- /usr/ports/devel/cocktail/work/cocktail-9309//./reuse/m2c/Checks.h	Tue Feb 15 14:26:46 1994
+++ ./reuse/m2c/Checks.h	Thu Aug  5 18:49:33 2004
@@ -1,4 +1,8 @@
 #define DEFINITION_Checks
 
+#ifndef DEFINITION_SYSTEM_
+#include "SYSTEM_.h"
+#endif
+
 extern void Checks_ErrorCheck ARGS((CHAR s[], LONGCARD , INTEGER n));
-extern void BEGIN_Checks();
+extern void BEGIN_Checks(NOARGS);
