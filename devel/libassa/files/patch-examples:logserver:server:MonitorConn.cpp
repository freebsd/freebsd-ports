--- examples/logserver/server/MonitorConn.cpp.orig	Thu Jan 29 08:53:46 2004
+++ examples/logserver/server/MonitorConn.cpp	Thu Jan 29 08:54:16 2004
@@ -19,6 +19,9 @@
 #include "Conn.h"
 #include "LogServer-main.h"
 #include "LogServer.h"
+#include <algorithm>
+
+using namespace std;
 
 /** Convert user input to upper case
  */
