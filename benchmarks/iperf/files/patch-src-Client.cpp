--- src/Client.cpp.orig	2017-08-09 03:54:14 UTC
+++ src/Client.cpp
@@ -680,7 +680,7 @@ void Client::Run( void ) {
 
         // store datagram ID into buffer
 	if (isSeqNo64b(mSettings)) {
-	    mBuf_UDP->id      = htonl((reportstruct->packetID & 0xFFFFFFFFFL));
+	    mBuf_UDP->id      = htonl((reportstruct->packetID & 0xFFFFFFFFL));
 	    mBuf_UDP->id2     = htonl((((reportstruct->packetID & 0xFFFFFFFF00000000LL) >> 32) | 0x80000000L));
 	} else {
 	    mBuf_UDP->id      = htonl(((reportstruct->packetID & 0xFFFFFFFFL) | 0x80000000L));
