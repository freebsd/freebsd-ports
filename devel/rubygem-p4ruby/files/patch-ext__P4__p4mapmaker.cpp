--- ./ext/P4/p4mapmaker.cpp.orig	2015-02-11 21:56:41.253726893 +0000
+++ ./ext/P4/p4mapmaker.cpp	2015-02-11 21:57:50.622092422 +0000
@@ -35,9 +35,9 @@
  ******************************************************************************/
 #include <ruby.h>
 #include "undefdups.h"
-#include <p4/clientapi.h>
-#include <p4/mapapi.h>
-#include <p4/debug.h>
+#include <perforce/clientapi.h>
+#include <perforce/mapapi.h>
+#include <perforce/debug.h>
 #include "p4rubydebug.h"
 #include "p4utils.h"
 #include "p4mapmaker.h"
