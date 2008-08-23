
FreeBSD does not have header file util.h, fortunately it is not needed.
Add header file time.h for time().

--- src/logutmp.c.orig	2006-12-04 16:13:22.000000000 -0500
+++ src/logutmp.c	2006-12-04 16:13:22.000000000 -0500
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
 
