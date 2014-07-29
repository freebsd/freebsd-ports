--- rts/alloc.c.orig	Sat Dec 13 19:57:23 2003
+++ rts/alloc.c	Sat Dec 13 19:57:00 2003
@@ -5,7 +5,7 @@
  */
 
 #include "rts.h"
-#include <varargs.h>
+#include <stdarg.h>
 
 static Memh all_mem;	/* header blocks for SR allocated memory */
 static Mutex mem_mutex;	/* protection for all_mem; acquired after res->rmutex.*/
