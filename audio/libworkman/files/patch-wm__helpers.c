--- wm_helpers.c.orig	1999-03-07 08:36:41 UTC
+++ wm_helpers.c
@@ -30,7 +30,7 @@ static char wm_helpers_id[] = "$Id: wm_h
 
 #include <stdio.h>
 #include <string.h>
-#include <malloc.h>
+#include <stdlib.h>
 #include <errno.h>
 #include <stdarg.h>
 #include <sys/time.h>
