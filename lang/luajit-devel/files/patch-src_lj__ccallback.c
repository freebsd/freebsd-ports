--- src/lj_ccallback.c.orig	2020-10-28 11:55:44 UTC
+++ src/lj_ccallback.c
@@ -20,6 +20,7 @@
 #include "lj_mcode.h"
 #include "lj_trace.h"
 #include "lj_vm.h"
+#include "lualib.h"
 
 /* -- Target-specific handling of callback slots -------------------------- */
 
