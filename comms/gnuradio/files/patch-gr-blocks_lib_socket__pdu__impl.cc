--- gr-blocks/lib/socket_pdu_impl.cc.orig	2019-04-16 13:45:00 UTC
+++ gr-blocks/lib/socket_pdu_impl.cc
@@ -165,8 +165,11 @@ namespace gr {
     void
     socket_pdu_impl::start_tcp_accept()
     {
-      tcp_connection::sptr new_connection = tcp_connection::make(d_acceptor_tcp->get_io_service(), d_rxbuf.size(), d_tcp_no_delay);
-
+#if (BOOST_VERSION >= 107000)
+	tcp_connection::sptr new_connection = tcp_connection::make(d_io_service, d_rxbuf.size(), d_tcp_no_delay);
+#else
+	tcp_connection::sptr new_connection = tcp_connection::make(d_acceptor_tcp->get_io_service(), d_rxbuf.size(), d_tcp_no_delay);
+#endif
       d_acceptor_tcp->async_accept(new_connection->socket(),
         boost::bind(&socket_pdu_impl::handle_tcp_accept, this,
           new_connection, boost::asio::placeholders::error));
