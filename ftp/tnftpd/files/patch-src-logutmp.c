
FreeBSD does not have header file util.h, fortunately it is not needed.
Add header file time.h for time().

--- src/logutmp.c.orig	Wed Dec 13 13:16:58 2006
+++ src/logutmp.c	Wed Dec 13 13:17:18 2006
@@ -59,13 +59,13 @@
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
 
