--- ./calendar/libedata-cal/e-cal-backend-intervaltree.c.orig	2011-01-18 17:09:50.000000000 +0000
+++ ./calendar/libedata-cal/e-cal-backend-intervaltree.c	2011-01-18 17:09:59.000000000 +0000
@@ -26,7 +26,7 @@
 
 #include <stdio.h>
 #include <string.h>
-#include <malloc.h>
+#include <stdlib.h>
 
 #include "e-cal-backend-intervaltree.h"
 
