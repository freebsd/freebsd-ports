
$FreeBSD$

--- providers/gda-default-server/sqlite/lemon.c.orig	Fri Aug  3 17:47:37 2001
+++ providers/gda-default-server/sqlite/lemon.c	Mon Aug  6 10:59:21 2001
@@ -1327,7 +1327,7 @@
 /*
 ** Return a pointer to the next structure in the linked list.
 */
-#define NEXT(A) (*(char**)(((int)A)+offset))
+#define NEXT(A) (*(char**)(((long)A)+offset))
 
 /*
 ** Inputs:
