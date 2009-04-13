--- ./src/logentry.c.orig	2009-04-13 11:10:16.000000000 -0400
+++ ./src/logentry.c	2009-04-13 11:10:38.000000000 -0400
@@ -21,6 +21,7 @@
  */
 
 
+#include <svn_props.h>
 #include <svn_repos.h>
 
 #include "logentry.h"
