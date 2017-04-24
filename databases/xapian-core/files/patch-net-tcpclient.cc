--- net/tcpclient.cc.orig	2017-04-24 02:19:20 UTC
+++ net/tcpclient.cc
@@ -25,7 +25,6 @@
 #include "tcpclient.h"
 
 #include "remoteconnection.h"
-#include "resolver.h"
 #include "str.h"
 #include <xapian/error.h>
 
@@ -36,6 +35,7 @@
 #include "safesysselect.h"
 #include "safesyssocket.h"
 #include "socket_utils.h"
+#include "resolver.h"
 
 #include <cmath>
 #include <cstring>
