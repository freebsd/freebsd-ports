--- ./ext/P4/specmgr.cpp.orig	2015-02-11 21:56:41.261843618 +0000
+++ ./ext/P4/specmgr.cpp	2015-02-11 21:58:06.073099450 +0000
@@ -38,10 +38,10 @@
 #include <ruby.h>
 #include "p4utils.h"
 #include "undefdups.h"
-#include <p4/clientapi.h>
-#include <p4/strops.h>
-#include <p4/spec.h>
-#include <p4/strtable.h>
+#include <perforce/clientapi.h>
+#include <perforce/strops.h>
+#include <perforce/spec.h>
+#include <perforce/strtable.h>
 #include "p4rubyconf.h"
 #include "gc_hack.h"
 #include "p4rubydebug.h"
