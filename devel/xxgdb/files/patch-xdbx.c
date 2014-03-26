--- xdbx.c.orig	1995-04-20 19:37:31.000000000 -0700
+++ xdbx.c	2014-03-25 20:54:19.951463142 -0700
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
