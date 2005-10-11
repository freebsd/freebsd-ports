--- ./src/3dsparse/aseFile.tab.cpp.orig	Sat Aug  6 13:57:38 2005
+++ ./src/3dsparse/aseFile.tab.cpp	Tue Aug  9 23:21:13 2005
@@ -329,10 +329,10 @@
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
