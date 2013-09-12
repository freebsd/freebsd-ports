--- ./examples/some_notify_clients.cc.orig	2003-10-12 20:51:18.000000000 +0200
+++ ./examples/some_notify_clients.cc	2013-09-12 19:38:14.830059760 +0200
@@ -4,7 +4,8 @@
 #endif
 
 #include <stdlib.h>
-#include <iostream.h>
+#include <iostream>
+using namespace std;
 
 #include "orb_init_name.h"
 #include "get_channel.h"
