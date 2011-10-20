--- vector/v.info/main.c.orig	2011-10-18 23:12:56.000000000 +0000
+++ vector/v.info/main.c	2011-10-18 23:13:19.000000000 +0000
@@ -17,6 +17,7 @@
  **************************************************************/
 #include <string.h>
 #include <stdlib.h>
+#include <sys/types.h>
 #include <grass/gis.h>
 #include <grass/Vect.h>
 #include <grass/dbmi.h>
