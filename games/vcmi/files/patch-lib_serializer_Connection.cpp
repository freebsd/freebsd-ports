--- lib/serializer/Connection.cpp.orig	2023-02-03 09:25:08 UTC
+++ lib/serializer/Connection.cpp
@@ -15,6 +15,7 @@
 #include "../CGameState.h"
 
 #include <boost/asio.hpp>
+#include <sys/sysctl.h>
 
 VCMI_LIB_NAMESPACE_BEGIN
 
@@ -46,8 +47,13 @@ void CConnection::init()
 	socket->set_option(boost::asio::ip::tcp::no_delay(true));
     try
     {
-        socket->set_option(boost::asio::socket_base::send_buffer_size(4194304));
-        socket->set_option(boost::asio::socket_base::receive_buffer_size(4194304));
+	unsigned long sb_max, sb_max_adj;
+	size_t len = sizeof(sb_max);
+	(void)sysctlbyname("kern.ipc.maxsockbuf", &sb_max, &len, NULL, 0);
+	sb_max_adj = sb_max * MCLBYTES / (MSIZE + MCLBYTES);
+
+	socket->set_option(boost::asio::socket_base::send_buffer_size(sb_max_adj));
+	socket->set_option(boost::asio::socket_base::receive_buffer_size(sb_max_adj));
     }
     catch (const boost::system::system_error & e)
     {
