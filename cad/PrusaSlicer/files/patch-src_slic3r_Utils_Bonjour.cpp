--- src/slic3r/Utils/Bonjour.cpp.orig	2025-02-14 23:36:08 UTC
+++ src/slic3r/Utils/Bonjour.cpp
@@ -624,7 +624,7 @@ UdpSession::UdpSession(Bonjour::ReplyFn rfn) : replyfn
 	buffer.resize(DnsMessage::MAX_SIZE);
 }
 
-UdpSocket::UdpSocket( Bonjour::ReplyFn replyfn, const asio::ip::address& multicast_address, const asio::ip::address& interface_address, std::shared_ptr< boost::asio::io_service > io_service)
+UdpSocket::UdpSocket( Bonjour::ReplyFn replyfn, const asio::ip::address& multicast_address, const asio::ip::address& interface_address, std::shared_ptr< boost::asio::io_context > io_service)
 	: replyfn(replyfn)
 	, multicast_address(multicast_address)
 	, socket(*io_service)
@@ -658,7 +658,7 @@ UdpSocket::UdpSocket( Bonjour::ReplyFn replyfn, const 
 }
 
 
-UdpSocket::UdpSocket( Bonjour::ReplyFn replyfn, const asio::ip::address& multicast_address, std::shared_ptr< boost::asio::io_service > io_service)
+UdpSocket::UdpSocket( Bonjour::ReplyFn replyfn, const asio::ip::address& multicast_address, std::shared_ptr< boost::asio::io_context > io_service)
 	: replyfn(replyfn)
 	, multicast_address(multicast_address)
 	, socket(*io_service)
@@ -714,7 +714,7 @@ void UdpSocket::receive_handler(SharedSession session,
 	// let io_service to handle the datagram on session
 	// from boost documentation io_service::post:
 	// The io_service guarantees that the handler will only be called in a thread in which the run(), run_one(), poll() or poll_one() member functions is currently being invoked.
-	io_service->post(boost::bind(&UdpSession::handle_receive, session, error, bytes));
+	io_service->get_executor().post(boost::bind(&UdpSession::handle_receive, session, error, bytes),std::allocator<void>());
 	// immediately accept new datagrams
 	async_receive();
 }
@@ -871,7 +871,7 @@ void Bonjour::priv::lookup_perform()
 {
 	service_dn = (boost::format("_%1%._%2%.local") % service % protocol).str();
 
-	std::shared_ptr< boost::asio::io_service > io_service(new boost::asio::io_service);
+	std::shared_ptr< boost::asio::io_context > io_service(new boost::asio::io_context);
 
 	std::vector<LookupSocket*> sockets;
 
@@ -966,7 +966,7 @@ void Bonjour::priv::resolve_perform()
 			rpls.push_back(reply);
 	};
 
-	std::shared_ptr< boost::asio::io_service > io_service(new boost::asio::io_service);
+	std::shared_ptr< boost::asio::io_context > io_service(new boost::asio::io_context);
 	std::vector<ResolveSocket*> sockets;
 
 	// resolve interfaces - from PR#6646
