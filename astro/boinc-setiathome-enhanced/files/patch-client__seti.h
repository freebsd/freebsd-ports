--- client/seti.h.orig	2009-01-26 18:01:09.000000000 +0100
+++ client/seti.h	2013-08-06 18:48:50.000000000 +0200
@@ -35,8 +35,6 @@
 #include <vector>
 #include "boinc_api.h"
 
-#define boinc_fpops_cumulative(x) boinc_ops_cumulative(x,0)
-
 extern APP_INIT_DATA app_init_data;
 
 #include "analyze.h"
