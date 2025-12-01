- Add missing Boost headers for deadline_timer and posix_time

--- src/cpp/session/SessionConsoleProcessSocketTests.cpp.orig	2025-11-30 07:52:46 UTC
+++ src/cpp/session/SessionConsoleProcessSocketTests.cpp
@@ -21,6 +21,8 @@
 #include <boost/enable_shared_from_this.hpp>
 #include <boost/lexical_cast.hpp>
 #include <boost/bind/bind.hpp>
+#include <boost/asio/deadline_timer.hpp>
+#include <boost/date_time/posix_time/posix_time.hpp>
 
 #include <websocketpp/config/asio_no_tls_client.hpp>
 #include <websocketpp/client.hpp>
