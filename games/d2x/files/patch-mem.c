--- mem/mem.c.orig	Mon Apr  5 15:37:36 2004
+++ mem/mem.c	Mon Apr  5 15:38:11 2004
@@ -34,11 +34,6 @@
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
