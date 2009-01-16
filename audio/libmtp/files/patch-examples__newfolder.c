--- ./examples/newfolder.c.orig	2009-01-14 01:16:16.000000000 +0300
+++ ./examples/newfolder.c	2009-01-14 01:16:31.000000000 +0300
@@ -22,6 +22,7 @@
  */
 #include "common.h"
 #include "pathutils.h"
+#include <stdlib.h>
 #include <libgen.h>
 
 void newfolder_function(char *);
