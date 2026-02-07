--- src/ObjectSystem/socketStuff.cc.orig	2018-09-17 10:38:45 UTC
+++ src/ObjectSystem/socketStuff.cc
@@ -230,7 +230,7 @@ SocketManagerSymbol::createServerTcpSocket(FreeDagNode
 	sockName.sin_family = AF_INET;
 	sockName.sin_port = htons(port);
 	sockName.sin_addr.s_addr = htonl(INADDR_ANY);  // HACK - what is the portable way to set this?
-	if (bind(fd, reinterpret_cast<sockaddr*>(&sockName), sizeof(sockName)) == -1)
+	if (::bind(fd, reinterpret_cast<sockaddr*>(&sockName), sizeof(sockName)) == -1)
 	  {
 	    const char* errText = strerror(errno);
 	    DebugAdvisory("unexpected bind() error with fd " << fd << ": " << errText);
