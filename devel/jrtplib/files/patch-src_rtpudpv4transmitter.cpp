--- src/rtpudpv4transmitter.cpp.orig	2017-03-28 16:59:02 UTC
+++ src/rtpudpv4transmitter.cpp
@@ -188,7 +188,7 @@ int GetAutoSockets(uint32_t bindIP, bool
 		addr.sin_family = AF_INET;
 		addr.sin_port = 0;
 		addr.sin_addr.s_addr = htonl(bindIP);
-		if (bind(sock,(struct sockaddr *)&addr,sizeof(struct sockaddr_in)) != 0)
+		if (::bind(sock,(struct sockaddr *)&addr,sizeof(struct sockaddr_in)) != 0)
 		{
 			RTPCLOSE(sock);
 			for (size_t i = 0 ; i < toClose.size() ; i++)
@@ -255,7 +255,7 @@ int GetAutoSockets(uint32_t bindIP, bool
 				addr.sin_family = AF_INET;
 				addr.sin_port = htons(secondPort);
 				addr.sin_addr.s_addr = htonl(bindIP);
-				if (bind(sock2,(struct sockaddr *)&addr,sizeof(struct sockaddr_in)) == 0)
+				if (::bind(sock2,(struct sockaddr *)&addr,sizeof(struct sockaddr_in)) == 0)
 				{
 					// In this case, we have two consecutive port numbers, the lower of
 					// which is even
@@ -399,7 +399,7 @@ int RTPUDPv4Transmitter::Create(size_t m
 			addr.sin_family = AF_INET;
 			addr.sin_port = htons(params->GetPortbase());
 			addr.sin_addr.s_addr = htonl(bindIP);
-			if (bind(rtpsock,(struct sockaddr *)&addr,sizeof(struct sockaddr_in)) != 0)
+			if (::bind(rtpsock,(struct sockaddr *)&addr,sizeof(struct sockaddr_in)) != 0)
 			{
 				CLOSESOCKETS;
 				MAINMUTEX_UNLOCK
@@ -422,7 +422,7 @@ int RTPUDPv4Transmitter::Create(size_t m
 				addr.sin_family = AF_INET;
 				addr.sin_port = htons(rtcpport);
 				addr.sin_addr.s_addr = htonl(bindIP);
-				if (bind(rtcpsock,(struct sockaddr *)&addr,sizeof(struct sockaddr_in)) != 0)
+				if (::bind(rtcpsock,(struct sockaddr *)&addr,sizeof(struct sockaddr_in)) != 0)
 				{
 					CLOSESOCKETS;
 					MAINMUTEX_UNLOCK
