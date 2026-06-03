--- src/slic3r/Utils/Bonjour.hpp.orig	2025-10-02 17:32:12 UTC
+++ src/slic3r/Utils/Bonjour.hpp
@@ -151,11 +151,11 @@ class UdpSocket (public)
 	UdpSocket(Bonjour::ReplyFn replyfn
 		, const boost::asio::ip::address& multicast_address
 		, const boost::asio::ip::address& interface_address
-		, std::shared_ptr< boost::asio::io_service > io_service);
+		, std::shared_ptr< boost::asio::io_context > io_service);
 
 	UdpSocket(Bonjour::ReplyFn replyfn
 		, const boost::asio::ip::address& multicast_address
-		, std::shared_ptr< boost::asio::io_service > io_service);
+		, std::shared_ptr< boost::asio::io_context > io_service);
 
 	void send();
 	void async_receive();
@@ -168,7 +168,7 @@ class UdpSocket (public)
 	boost::asio::ip::address					    multicast_address;
 	boost::asio::ip::udp::socket					socket;
 	boost::asio::ip::udp::endpoint					mcast_endpoint;
-	std::shared_ptr< boost::asio::io_service >	io_service;
+	std::shared_ptr< boost::asio::io_context >	io_service;
 	std::vector<BonjourRequest>						requests;
 };
 
@@ -182,7 +182,7 @@ class LookupSocket : public UdpSocket (public)
 		, Bonjour::ReplyFn replyfn
 		, const boost::asio::ip::address& multicast_address
 		, const boost::asio::ip::address& interface_address
-		, std::shared_ptr< boost::asio::io_service > io_service)
+		, std::shared_ptr< boost::asio::io_context > io_service)
 		: UdpSocket(replyfn, multicast_address, interface_address, io_service)
 		, txt_keys(txt_keys)
 		, service(service)
@@ -199,7 +199,7 @@ class LookupSocket : public UdpSocket (public)
 		, std::string protocol
 		, Bonjour::ReplyFn replyfn
 		, const boost::asio::ip::address& multicast_address
-		, std::shared_ptr< boost::asio::io_service > io_service)
+		, std::shared_ptr< boost::asio::io_context > io_service)
 		: UdpSocket(replyfn, multicast_address, io_service)
 		, txt_keys(txt_keys)
 		, service(service)
@@ -237,7 +237,7 @@ class ResolveSocket : public UdpSocket (public)
 		, Bonjour::ReplyFn replyfn
 		, const boost::asio::ip::address& multicast_address
 		, const boost::asio::ip::address& interface_address
-		, std::shared_ptr< boost::asio::io_service > io_service)
+		, std::shared_ptr< boost::asio::io_context > io_service)
 		: UdpSocket(replyfn, multicast_address, interface_address, io_service)
 		, hostname(hostname)
 
@@ -249,7 +249,7 @@ class ResolveSocket : public UdpSocket (public)
 	ResolveSocket(const std::string& hostname
 		, Bonjour::ReplyFn replyfn
 		, const boost::asio::ip::address& multicast_address
-		, std::shared_ptr< boost::asio::io_service > io_service)
+		, std::shared_ptr< boost::asio::io_context > io_service)
 		: UdpSocket(replyfn, multicast_address, io_service)
 		, hostname(hostname)
 
