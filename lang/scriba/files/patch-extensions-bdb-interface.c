--- extensions/bdb/interface.c.orig	Tue Mar  1 18:07:08 2005
+++ extensions/bdb/interface.c	Tue Mar  1 19:36:14 2005
@@ -11,7 +11,7 @@
 
 These lines are needed by the configurator to generate the file 'libraries.jim'
 NTLIBS: libdb41s.lib
-UXLIBS: -lbdb
+UXLIBS: -ldb41
 
 */
 #include <sys/types.h>
@@ -22,7 +22,7 @@
 #include <stdlib.h>
 #include <string.h>
 
-#include <db.h>
+#include <db41/db.h>
 
 #include "../../basext.h"
 
