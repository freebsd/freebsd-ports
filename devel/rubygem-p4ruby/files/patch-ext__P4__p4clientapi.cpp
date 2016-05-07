--- ./ext/P4/p4clientapi.cpp.orig	2015-02-11 21:56:41.253726893 +0000
+++ ./ext/P4/p4clientapi.cpp	2015-02-11 21:57:42.902119989 +0000
@@ -36,13 +36,13 @@
  ******************************************************************************/
 #include <ruby.h>
 #include "undefdups.h"
-#include <p4/clientapi.h>
-#include <p4/i18napi.h>
-#include <p4/enviro.h>
-#include <p4/hostenv.h>
-#include <p4/spec.h>
-#include <p4/ignore.h>
-#include <p4/debug.h>
+#include <perforce/clientapi.h>
+#include <perforce/i18napi.h>
+#include <perforce/enviro.h>
+#include <perforce/hostenv.h>
+#include <perforce/spec.h>
+#include <perforce/ignore.h>
+#include <perforce/debug.h>
 #include "p4result.h"
 #include "p4rubydebug.h"
 #include "clientuserruby.h"
