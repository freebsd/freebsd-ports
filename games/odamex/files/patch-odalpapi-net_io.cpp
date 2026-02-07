--- odalpapi/net_io.cpp	2014-06-16 17:33:15.000000000 +0200
+++ odalpapi/net_io.cpp	2014-06-16 17:33:44.000000000 +0200
@@ -34,6 +34,7 @@
 #include <sstream>
 #include <time.h>
 #include <errno.h>
+#include <unistd.h>
 
 #include "net_io.h"
 #include "net_utils.h"
@@ -45,7 +46,6 @@
 #ifdef _WIN32
 	#define AI_ALL 0x00000100
 #else
-	#include <unistd.h>
 	#define closesocket close
 	const int INVALID_SOCKET = -1;
 #endif
