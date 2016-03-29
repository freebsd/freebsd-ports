--- ./ext/P4/p4specdata.cpp.orig	2015-02-11 21:56:41.261843618 +0000
+++ ./ext/P4/p4specdata.cpp	2015-02-11 21:58:02.592245739 +0000
@@ -38,10 +38,10 @@
 
 #include <ruby.h>
 #include "undefdups.h"
-#include <p4/clientapi.h>
-#include <p4/i18napi.h>
-#include <p4/spec.h>
-#include <p4/debug.h>
+#include <perforce/clientapi.h>
+#include <perforce/i18napi.h>
+#include <perforce/spec.h>
+#include <perforce/debug.h>
 #include "p4rubydebug.h"
 #include "p4utils.h"
 #include "p4specdata.h"
