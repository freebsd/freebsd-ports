--- src/openhbci/core/statusreport.cpp.orig	2003-05-21 16:01:41.000000000 +0400
+++ src/openhbci/core/statusreport.cpp	2014-07-03 13:52:40.000000000 +0400
@@ -29,6 +29,7 @@
 #include "statusreport.h"
 #include "hbcistring.h"
 #include <assert.h>
+#include <stdlib.h> // for atoi()
 
 namespace HBCI {
 
