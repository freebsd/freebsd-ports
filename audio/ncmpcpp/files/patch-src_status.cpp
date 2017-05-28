--- src/status.cpp.orig	2017-05-25 13:30:40 UTC
+++ src/status.cpp
@@ -21,6 +21,8 @@
 #include <boost/date_time/posix_time/posix_time.hpp>
 #include <netinet/tcp.h>
 #include <netinet/in.h>
+#include <sys/types.h>
+#include <sys/socket.h>
 
 #include "curses/menu_impl.h"
 #include "screens/browser.h"
