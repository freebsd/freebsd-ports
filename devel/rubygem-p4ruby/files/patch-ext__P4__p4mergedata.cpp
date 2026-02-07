--- ./ext/P4/p4mergedata.cpp.orig	2015-02-11 21:56:41.253726893 +0000
+++ ./ext/P4/p4mergedata.cpp	2015-02-11 21:57:54.274440052 +0000
@@ -35,10 +35,10 @@
  ******************************************************************************/
 #include <ruby.h>
 #include "undefdups.h"
-#include <p4/clientapi.h>
-#include <p4/i18napi.h>
-#include <p4/strtable.h>
-#include <p4/spec.h>
+#include <perforce/clientapi.h>
+#include <perforce/i18napi.h>
+#include <perforce/strtable.h>
+#include <perforce/spec.h>
 #include "p4result.h"
 #include "p4rubydebug.h"
 #include "clientuserruby.h"
