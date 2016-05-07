--- ./ext/P4/clientprogressruby.cpp.orig	2015-02-11 21:56:41.253726893 +0000
+++ ./ext/P4/clientprogressruby.cpp	2015-02-11 21:57:19.286226444 +0000
@@ -39,8 +39,8 @@
 #include "gc_hack.h"
 #include "extconf.h"
 #include "p4utils.h"
-#include "p4/clientapi.h"
-#include "p4/clientprog.h"
+#include "perforce/clientapi.h"
+#include "perforce/clientprog.h"
 #include "clientprogressruby.h"
 
 extern VALUE eP4;
