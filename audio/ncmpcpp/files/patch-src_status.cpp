--- src/status.cpp.orig	2016-04-17 05:41:01 UTC
+++ src/status.cpp
@@ -21,6 +21,8 @@
 #include <boost/date_time/posix_time/posix_time.hpp>
 #include <netinet/tcp.h>
 #include <netinet/in.h>
+#include <sys/types.h>
+#include <sys/socket.h>
 
 #include "browser.h"
 #include "charset.h"
