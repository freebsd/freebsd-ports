--- src/logutmp.c-orig	Thu Jan 29 15:43:57 2004
+++ src/logutmp.c	Thu Jan 29 15:44:33 2004
@@ -60,13 +60,13 @@
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
+#include <time.h>
 #include <ttyent.h>
 #include <unistd.h>
 #include <utmp.h>
 #ifdef SUPPORT_UTMPX
 #include <utmpx.h>
 #endif
-#include <util.h>
 
 #include "extern.h"
 
