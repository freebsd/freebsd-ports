--- ./ext/P4/p4.cpp.orig	2015-02-11 21:56:41.253726893 +0000
+++ ./ext/P4/p4.cpp	2015-02-11 21:57:38.243472610 +0000
@@ -36,10 +36,10 @@
  ******************************************************************************/
 #include <ruby.h>
 #include "undefdups.h"
-#include <p4/clientapi.h>
-#include <p4/strtable.h>
-#include <p4/spec.h>
-#include <p4/ident.h>
+#include <perforce/clientapi.h>
+#include <perforce/strtable.h>
+#include <perforce/spec.h>
+#include <perforce/ident.h>
 #include "p4result.h"
 #include "specmgr.h"
 #include "clientuserruby.h"
