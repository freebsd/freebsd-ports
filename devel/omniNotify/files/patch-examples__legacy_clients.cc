--- ./examples/legacy_clients.cc.orig	2003-10-23 06:39:11.000000000 +0200
+++ ./examples/legacy_clients.cc	2013-09-12 19:42:16.061068521 +0200
@@ -4,8 +4,11 @@
 // See legacy_clients.h
 // -------------------------------------------------------------- //
 
-#include <iostream.h>
-#include <iomanip.h>
+#include <iostream>
+#include <iomanip>
+
+using namespace std;
+
 #include "thread_wrappers.h"
 
 #include "CosNotifyShorthands.h"
