--- ./ext/P4/p4result.cpp.orig	2015-02-11 21:56:41.261843618 +0000
+++ ./ext/P4/p4result.cpp	2015-02-11 21:57:58.250220456 +0000
@@ -37,7 +37,7 @@
 
 #include <ruby.h>
 #include "undefdups.h"
-#include <p4/clientapi.h>
+#include <perforce/clientapi.h>
 #include "gc_hack.h"
 #include "p4error.h"
 #include "p4utils.h"
