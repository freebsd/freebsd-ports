
$FreeBSD$

--- ../../tools/dbmalloc.c	2003/07/12 11:39:21	1.1
+++ ../../tools/dbmalloc.c	2003/07/12 11:39:30
@@ -27,7 +27,6 @@
 
 
 #include "config.h"
-#include "dbmalloc.h"
 #include <stdio.h>
 #if TARGET == TARGET_WINDOWS
 #include <io.h>
@@ -35,6 +34,7 @@
 #include <unistd.h>
 #endif /* TARGET */
 
+#include "dbmalloc.h"
 
 #if MP_IDENT_SUPPORT
 #ident "$Id: dbmalloc.c,v 1.1 2003/07/12 11:39:21 root Exp root $"
