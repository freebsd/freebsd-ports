--- xdbx.c.orig	1995-04-21 02:37:31 UTC
+++ xdbx.c
@@ -74,11 +74,9 @@
 #define XGDBVERSION	"1.12"
 #endif
 
-#ifdef SYSV 
 #   include <stdio.h>
 #   include <stdlib.h>
 #   include <sys/param.h>
-#endif
 
 #include "global.h"
 #include "bitmaps.h"
