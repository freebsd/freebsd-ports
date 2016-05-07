--- ./ext/P4/clientuserruby.cpp.orig	2015-02-11 21:56:41.253726893 +0000
+++ ./ext/P4/clientuserruby.cpp	2015-02-11 21:57:33.343960720 +0000
@@ -37,10 +37,10 @@
 #include <ctype.h>
 #include <ruby.h>
 #include "undefdups.h"
-#include <p4/clientapi.h>
-#include <p4/clientprog.h>
-#include <p4/spec.h>
-#include <p4/diff.h>
+#include <perforce/clientapi.h>
+#include <perforce/clientprog.h>
+#include <perforce/spec.h>
+#include <perforce/diff.h>
 #include "p4rubyconf.h"
 #include "gc_hack.h"
 #include "p4result.h"
