--- ./src/3dsparse/aseFile.tab.cpp.orig	Mon Mar  1 18:48:17 2004
+++ ./src/3dsparse/aseFile.tab.cpp	Tue Jan 25 19:34:16 2005
@@ -327,10 +327,10 @@
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
