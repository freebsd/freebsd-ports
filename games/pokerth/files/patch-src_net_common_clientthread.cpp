--- src/net/common/clientthread.cpp.orig	2017-08-16 12:24:03 UTC
+++ src/net/common/clientthread.cpp
@@ -993,8 +993,12 @@ ClientThread::CreateContextSession()
 			newSock.reset(new boost::asio::ip::tcp::socket(*m_ioService, tcp::v6()));
 		else
 			newSock.reset(new boost::asio::ip::tcp::socket(*m_ioService, tcp::v4()));
+#if BOOST_VERSION < 106600
 		boost::asio::socket_base::non_blocking_io command(true);
 		newSock->io_control(command);
+#else
+		newSock->non_blocking(true);
+#endif
 		newSock->set_option(tcp::no_delay(true));
 		newSock->set_option(boost::asio::socket_base::keep_alive(true));
 
