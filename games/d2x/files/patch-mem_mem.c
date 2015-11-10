--- mem/mem.c.orig	2003-04-11 23:51:48 UTC
+++ mem/mem.c
@@ -34,11 +34,6 @@ COPYRIGHT 1993-1999 PARALLAX SOFTWARE CO
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
-#if defined(__APPLE__) && defined(__MACH__)
-#include <sys/malloc.h>
-#else
-#include <malloc.h>
-#endif
 #include "pstypes.h"
 #include "mono.h"
 #include "error.h"
