--- rts/lib/lobby/Connection.h.orig	2010-12-10 17:17:43.000000000 +0300
+++ rts/lib/lobby/Connection.h	2010-12-10 17:19:28.000000000 +0300
@@ -6,6 +6,7 @@
 #include <boost/asio/streambuf.hpp>
 #include <boost/asio/deadline_timer.hpp>
 #include <boost/asio/ip/tcp.hpp>
+#include <list>
 #include <string>
 
 struct ClientStatus
