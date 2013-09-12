--- ./examples/demo_offer_change.cc.orig	2003-10-12 20:51:18.000000000 +0200
+++ ./examples/demo_offer_change.cc	2013-09-12 19:41:00.165064073 +0200
@@ -1,7 +1,9 @@
 #include <stdlib.h>
-#include <iostream.h>
+#include <iostream>
 #include <stdio.h>
 
+using namespace std;
+
 #include "CosNotifyShorthands.h"
 #include "orb_init_name.h"
 #include "get_channel.h"
