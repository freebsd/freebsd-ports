--- src/status.cpp.orig	2015-11-04 20:01:29 UTC
+++ src/status.cpp
@@ -21,6 +21,8 @@
 #include <boost/date_time/posix_time/posix_time.hpp>
 #include <netinet/tcp.h>
 #include <netinet/in.h>
+#include <sys/types.h>
+#include <sys/socket.h>
 
 #include "browser.h"
 #include "charset.h"
