--- src/slic3r/Utils/Bonjour.hpp.orig	2024-12-20 11:54:34 UTC
+++ src/slic3r/Utils/Bonjour.hpp
@@ -13,6 +13,7 @@
 #include <functional>

 #include <boost/asio.hpp>
+#include <boost/asio/deadline_timer.hpp>
 #include <boost/asio/ip/address.hpp>
 #include <boost/optional.hpp>
 #include <boost/system/error_code.hpp>
@@ -155,11 +155,11 @@ class UdpSocket (public)
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
@@ -172,7 +172,7 @@ class UdpSocket (public)
 	boost::asio::ip::address					    multicast_address;
 	boost::asio::ip::udp::socket					socket;
 	boost::asio::ip::udp::endpoint					mcast_endpoint;
-	std::shared_ptr< boost::asio::io_service >	io_service;
+	std::shared_ptr< boost::asio::io_context >	io_service;
 	std::vector<BonjourRequest>						requests;
 };
 
@@ -186,7 +186,7 @@ class LookupSocket : public UdpSocket (public)
 		, Bonjour::ReplyFn replyfn
 		, const boost::asio::ip::address& multicast_address
 		, const boost::asio::ip::address& interface_address
-		, std::shared_ptr< boost::asio::io_service > io_service)
+		, std::shared_ptr< boost::asio::io_context > io_service)
 		: UdpSocket(replyfn, multicast_address, interface_address, io_service)
 		, txt_keys(txt_keys)
 		, service(service)
@@ -203,7 +203,7 @@ class LookupSocket : public UdpSocket (public)
 		, std::string protocol
 		, Bonjour::ReplyFn replyfn
 		, const boost::asio::ip::address& multicast_address
-		, std::shared_ptr< boost::asio::io_service > io_service)
+		, std::shared_ptr< boost::asio::io_context > io_service)
 		: UdpSocket(replyfn, multicast_address, io_service)
 		, txt_keys(txt_keys)
 		, service(service)
@@ -241,7 +241,7 @@ class ResolveSocket : public UdpSocket (public)
 		, Bonjour::ReplyFn replyfn
 		, const boost::asio::ip::address& multicast_address
 		, const boost::asio::ip::address& interface_address
-		, std::shared_ptr< boost::asio::io_service > io_service)
+		, std::shared_ptr< boost::asio::io_context > io_service)
 		: UdpSocket(replyfn, multicast_address, interface_address, io_service)
 		, hostname(hostname)
 
@@ -253,7 +253,7 @@ class ResolveSocket : public UdpSocket (public)
 	ResolveSocket(const std::string& hostname
 		, Bonjour::ReplyFn replyfn
 		, const boost::asio::ip::address& multicast_address
-		, std::shared_ptr< boost::asio::io_service > io_service)
+		, std::shared_ptr< boost::asio::io_context > io_service)
 		: UdpSocket(replyfn, multicast_address, io_service)
 		, hostname(hostname)
 
