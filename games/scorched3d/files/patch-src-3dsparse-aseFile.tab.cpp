--- ./src/3dsparse/aseFile.tab.cpp.orig	Fri Jan 23 17:58:58 2004
+++ ./src/3dsparse/aseFile.tab.cpp	Fri Jan 23 18:01:17 2004
@@ -330,10 +330,10 @@
 #include <alloca.h>
 #else /* not sparc */
 #if defined (MSDOS) && !defined (__TURBOC__)
-#include <malloc.h>
+#include <stdlib.h>
 #else /* not MSDOS, or __TURBOC__ */
 #if defined(_AIX)
-#include <malloc.h>
+#include <stdlib.h>
  #pragma alloca
 #else /* not MSDOS, __TURBOC__, or _AIX */
 #ifdef __hpux
