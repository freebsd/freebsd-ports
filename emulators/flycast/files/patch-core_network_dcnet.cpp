--- core/network/dcnet.cpp.orig	2025-07-18 15:30:48 UTC
+++ core/network/dcnet.cpp
@@ -222,7 +222,7 @@ class EthSocket (private)
 	}
 
 private:
-	using iterator = asio::buffers_iterator<asio::const_buffers_1>;
+	using iterator = asio::buffers_iterator<asio::const_buffer>;
 
 	std::pair<iterator, bool>
 	static packetMatcher(iterator begin, iterator end)
@@ -502,7 +502,7 @@ class AccessPointFinder (private)
 	{
 		std::error_code e;
 		socket.close(e);
-		timer.cancel(e);
+		timer.cancel();
 		if (ec) {
 			handler(ec, {}, {});
 		}
@@ -584,7 +584,7 @@ class DCNetThread (public)
 	{
 		if (io_context == nullptr || pppSocket == nullptr)
 			return;
-		io_context->post([this, v]() {
+		asio::post([this, v]() {
 			pppSocket->send(v);
 		});
 	}
@@ -593,7 +593,7 @@ class DCNetThread (public)
 		if (io_context != nullptr && ethSocket != nullptr)
 		{
 			std::vector<u8> vbuf(frame, frame + len);
-			io_context->post([this, vbuf]() {
+			asio::post([this, vbuf]() {
 				ethSocket->send(vbuf.data(), vbuf.size());
 			});
 		}
