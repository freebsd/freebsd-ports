--- src/status.cpp_orig	2014-11-16 09:21:55.651181899 +0100
+++ src/status.cpp	2014-11-16 09:21:59.233203196 +0100
@@ -21,6 +21,8 @@
 #include <boost/date_time/posix_time/posix_time.hpp>
 #include <netinet/tcp.h>
 #include <netinet/in.h>
+#include <sys/types.h>
+#include <sys/socket.h>
 
 #include "browser.h"
 #include "charset.h"
