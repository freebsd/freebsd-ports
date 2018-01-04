--- src/net/serveraccepthelper.h.orig	2017-08-16 12:24:03 UTC
+++ src/net/serveraccepthelper.h
@@ -122,8 +122,12 @@ class ServerAcceptHelper : public ServerAcceptInterfac
 					  const boost::system::error_code &error)
 	{
 		if (!error) {
+#if BOOST_VERSION < 106600
 			boost::asio::socket_base::non_blocking_io command(true);
 			acceptedSocket->io_control(command);
+#else
+			acceptedSocket->non_blocking(true);
+#endif
 			acceptedSocket->set_option(typename P::no_delay(true));
 			acceptedSocket->set_option(boost::asio::socket_base::keep_alive(true));
 			boost::shared_ptr<SessionData> sessionData(new SessionData(acceptedSocket, m_lobbyThread->GetNextSessionId(), m_lobbyThread->GetSessionDataCallback(), *m_ioService));
