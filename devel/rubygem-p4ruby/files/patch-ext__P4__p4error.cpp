--- ./ext/P4/p4error.cpp.orig	2015-02-11 21:56:41.253726893 +0000
+++ ./ext/P4/p4error.cpp	2015-02-11 21:57:46.404951840 +0000
@@ -35,7 +35,7 @@
  ******************************************************************************/
 #include <ruby.h>
 #include "undefdups.h"
-#include <p4/clientapi.h>
+#include <perforce/clientapi.h>
 #include "p4rubydebug.h"
 #include "p4utils.h"
 #include "p4error.h"
