--- src/slic3r/Utils/Bonjour.cpp.orig	2025-10-02 17:32:12 UTC
+++ src/slic3r/Utils/Bonjour.cpp
@@ -8,7 +8,6 @@
 #include <map>
 #include <thread>
 #include <boost/endian/conversion.hpp>
-#include <boost/date_time/posix_time/posix_time_duration.hpp>
 #include <boost/format.hpp>
 #include <boost/log/trivial.hpp>
 #include <boost/bind/bind.hpp>
@@ -620,7 +619,7 @@ UdpSession::UdpSession(Bonjour::ReplyFn rfn) : replyfn
 	buffer.resize(DnsMessage::MAX_SIZE);
 }
 
-UdpSocket::UdpSocket( Bonjour::ReplyFn replyfn, const asio::ip::address& multicast_address, const asio::ip::address& interface_address, std::shared_ptr< boost::asio::io_service > io_service)
+UdpSocket::UdpSocket( Bonjour::ReplyFn replyfn, const asio::ip::address& multicast_address, const asio::ip::address& interface_address, std::shared_ptr< boost::asio::io_context > io_service)
 	: replyfn(replyfn)
 	, multicast_address(multicast_address)
 	, socket(*io_service)
@@ -654,7 +653,7 @@ UdpSocket::UdpSocket( Bonjour::ReplyFn replyfn, const 
 }
 
 
-UdpSocket::UdpSocket( Bonjour::ReplyFn replyfn, const asio::ip::address& multicast_address, std::shared_ptr< boost::asio::io_service > io_service)
+UdpSocket::UdpSocket( Bonjour::ReplyFn replyfn, const asio::ip::address& multicast_address, std::shared_ptr< boost::asio::io_context > io_service)
 	: replyfn(replyfn)
 	, multicast_address(multicast_address)
 	, socket(*io_service)
@@ -710,7 +709,7 @@ void UdpSocket::receive_handler(SharedSession session,
 	// let io_service to handle the datagram on session
 	// from boost documentation io_service::post:
 	// The io_service guarantees that the handler will only be called in a thread in which the run(), run_one(), poll() or poll_one() member functions is currently being invoked.
-	io_service->post(boost::bind(&UdpSession::handle_receive, session, error, bytes));
+	io_service->get_executor().post(boost::bind(&UdpSession::handle_receive, session, error, bytes),std::allocator<void>());
 	// immediately accept new datagrams
 	async_receive();
 }
@@ -867,7 +866,7 @@ void Bonjour::priv::lookup_perform()
 {
 	service_dn = (boost::format("_%1%._%2%.local") % service % protocol).str();
 
-	std::shared_ptr< boost::asio::io_service > io_service(new boost::asio::io_service);
+	std::shared_ptr< boost::asio::io_context > io_service(new boost::asio::io_context);
 
 	std::vector<LookupSocket*> sockets;
 
@@ -919,7 +918,7 @@ void Bonjour::priv::lookup_perform()
 			socket->send();
 
 		// timer settings
-		asio::deadline_timer timer(*io_service);
+		asio::steady_timer timer(*io_service);
 		retries--;
 		std::function<void(const error_code&)> timer_handler = [&](const error_code& error) {
 			// end 
@@ -932,7 +931,7 @@ void Bonjour::priv::lookup_perform()
 			// restart timer
 			} else {
 				retries--;
-				timer.expires_from_now(boost::posix_time::seconds(timeout));
+				timer.expires_after(std::chrono::seconds(timeout));
 				timer.async_wait(timer_handler);
 				// trigger another round of queries
 				for (auto * socket : sockets)
@@ -940,7 +939,7 @@ void Bonjour::priv::lookup_perform()
 			}
 		};
 		// start timer
-		timer.expires_from_now(boost::posix_time::seconds(timeout));
+		timer.expires_after(std::chrono::seconds(timeout));
 		timer.async_wait(timer_handler);
 		// start io_service, it will run until it has something to do - so in this case until stop is called in timer
 		io_service->run();
@@ -962,7 +961,7 @@ void Bonjour::priv::resolve_perform()
 			rpls.push_back(reply);
 	};
 
-	std::shared_ptr< boost::asio::io_service > io_service(new boost::asio::io_service);
+	std::shared_ptr< boost::asio::io_context > io_service(new boost::asio::io_context);
 	std::vector<ResolveSocket*> sockets;
 
 	// resolve interfaces - from PR#6646
@@ -1012,7 +1011,7 @@ void Bonjour::priv::resolve_perform()
 			socket->send();
 
 		// timer settings
-		asio::deadline_timer timer(*io_service);
+		asio::steady_timer timer(*io_service);
 		retries--;
 		std::function<void(const error_code&)> timer_handler = [&](const error_code& error) {
 			int replies_count = replies.size();
@@ -1026,7 +1025,7 @@ void Bonjour::priv::resolve_perform()
 			// restart timer
 			} else {
 				retries--;
-				timer.expires_from_now(boost::posix_time::seconds(timeout));
++				timer.expires_after(std::chrono::seconds(timeout));
 				timer.async_wait(timer_handler);
 				// trigger another round of queries
 				for (auto * socket : sockets)
@@ -1034,7 +1033,7 @@ void Bonjour::priv::resolve_perform()
 			}
 		};
 		// start timer
-		timer.expires_from_now(boost::posix_time::seconds(timeout));
++		timer.expires_after(std::chrono::seconds(timeout));
 		timer.async_wait(timer_handler);
 		// start io_service, it will run until it has something to do - so in this case until stop is called in timer
 		io_service->run();
