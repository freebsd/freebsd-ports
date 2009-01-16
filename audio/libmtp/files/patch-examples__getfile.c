--- ./examples/getfile.c.orig	2009-01-14 01:15:17.000000000 +0300
+++ ./examples/getfile.c	2009-01-14 01:16:03.000000000 +0300
@@ -22,6 +22,8 @@
  */
 #include "common.h"
 #include "pathutils.h"
+#include <stdlib.h>
+#include <limits.h>
 
 void getfile_function(char *,char *);
 void getfile_command(int, char **);
