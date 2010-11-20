--- calendar/libedata-cal/e-cal-backend-intervaltree.c.orig	2010-09-19 18:17:35.000000000 +0000
+++ calendar/libedata-cal/e-cal-backend-intervaltree.c	2010-09-19 18:17:44.000000000 +0000
@@ -26,7 +26,7 @@
 
 #include <stdio.h>
 #include <string.h>
-#include <malloc.h>
+#include <stdlib.h>
 
 #include "e-cal-backend-intervaltree.h"
 
