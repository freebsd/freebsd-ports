--- regex.c--	Mon Dec  1 23:48:17 1997
+++ regex.c	Wed Apr 28 12:59:44 1999
@@ -4,6 +4,9 @@
    author:  george j. carrette
  */
 
+#if defined(HAVE_SYS_PARAM_H)
+#include <sys/param.h>
+#endif
 
 #include <stdio.h>
 #include <stdlib.h>
@@ -11,7 +14,7 @@
 #if defined(VMS)
 #include <types.h>
 #endif
-#if defined(sgi)
+#if defined(sgi) || defined(BSD)
 #include <sys/types.h>
 #endif
 #include <regex.h>
