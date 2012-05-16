--- src/server.cpp.orig	2012-03-12 10:21:03.000000000 +0300
+++ src/server.cpp	2012-03-12 10:21:15.000000000 +0300
@@ -37,7 +37,7 @@
 private:
 	void start_accept()
 	{
-		socket_ptr socket(new tcp::socket(acceptor_.io_service()));
+		socket_ptr socket(new tcp::socket(acceptor_.get_io_service()));
 		acceptor_.async_accept(*socket, boost::bind(&server::handle_accept, this, socket, boost::asio::placeholders::error));
 	}
 
