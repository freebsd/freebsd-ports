--- assa/UnConUDPSocket.cpp.orig	Mon Mar 29 12:11:09 2004
+++ assa/UnConUDPSocket.cpp	Mon Mar 29 12:11:45 2004
@@ -34,7 +34,7 @@
 	// recvfrom() returns zeroed out address structure!!!
 
 	int len;
-	size_t pa_len = peer_addr_->getLength();
+	socklen_t pa_len = peer_addr_->getLength();
 	SA* pa = peer_addr_->getAddress();
 
 	len = ::recvfrom(getHandler(), buf_, size_, 0, pa, 
