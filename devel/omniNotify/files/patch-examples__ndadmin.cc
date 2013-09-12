--- ./examples/ndadmin.cc.orig	2003-10-12 20:51:18.000000000 +0200
+++ ./examples/ndadmin.cc	2013-09-12 19:43:36.397068857 +0200
@@ -6,7 +6,9 @@
 #error COS_USES_BOA should not be set for this example
 #endif
 
-#include <iostream.h>
+#include <iostream>
+
+using namespace std;
 
 #include "orb_init_name.h"
 #include "get_channel.h"
