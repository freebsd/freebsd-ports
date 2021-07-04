--- include/gis.h.orig	2021-07-04 15:25:28 UTC
+++ include/gis.h
@@ -23,6 +23,7 @@
 /* System include files */
 #include <stdio.h>
 #include <stdarg.h>
+#include <stdbool.h>
 
 /* Grass and local include files */
 #include <grass/config.h>
@@ -53,11 +54,11 @@ static const char *GRASS_copyright __attribute__ ((unu
 
 /* Define TRUE and FALSE for boolean comparisons */
 #ifndef TRUE
-#define TRUE 1
+#define TRUE true
 #endif
 
 #ifndef FALSE
-#define FALSE 0
+#define FALSE false
 #endif
 
 #if defined(_FILE_OFFSET_BITS) && _FILE_OFFSET_BITS == 64
