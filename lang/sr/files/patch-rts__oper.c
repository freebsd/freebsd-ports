--- rts/oper.c.orig	Sat Dec 13 20:00:05 2003
+++ rts/oper.c	Sat Dec 13 20:00:13 2003
@@ -1,6 +1,6 @@
 /*  oper.c -- runtime support of operations  */
 
-#include <varargs.h>
+#include <stdarg.h>
 #include "rts.h"
 
 static Pool oper_pool;		/* pool of operation descriptors */
