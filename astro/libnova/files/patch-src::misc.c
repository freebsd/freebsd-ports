--- src/misc.c.orig	Sun Jan 25 17:18:32 2004
+++ src/misc.c	Sun Jan 25 17:18:42 2004
@@ -44,9 +44,6 @@
 #include <ctype.h>
 #include "libnova.h"
 
-#ifndef __APPLE__
-#include <malloc.h>
-#endif
 
 /* local types and macros */
 typedef int BOOL;
