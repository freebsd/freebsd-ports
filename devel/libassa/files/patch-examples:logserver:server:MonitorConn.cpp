--- examples/logserver/server/MonitorConn.cpp.orig	Thu Jul 20 10:30:55 2006
+++ examples/logserver/server/MonitorConn.cpp	Thu Sep  7 16:18:01 2006
@@ -20,6 +20,8 @@
 #include "LogServer-main.h"
 #include "LogServer.h"
 
+#include <algorithm>
+
 /** Convert user input to upper case
  */
 template <class T>
