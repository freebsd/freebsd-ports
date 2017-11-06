--- rds/src/ruterror.h.orig	2002-04-25 14:13:59 UTC
+++ rds/src/ruterror.h
@@ -46,7 +46,7 @@
 |                                                             |
 \------------------------------------------------------------*/
 
-extern char *basename();
+#include <libgen.h>
 
 # define ruterror( E, V ) (rut_error( (E), (V), basename(__FILE__), __LINE__ ))
 
