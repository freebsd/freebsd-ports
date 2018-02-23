--- src/network/C4NetIO.cpp.orig	2018-02-04 15:39:08 UTC
+++ src/network/C4NetIO.cpp
@@ -523,6 +523,11 @@ C4NetIO::HostAddress::AddressFamily C4Ne
 		gen.sa_family == AF_INET6 ? IPv6 : UnknownFamily;
 }
 
+size_t C4NetIO::HostAddress::GetAddrLen() const
+{
+	return GetFamily() == IPv4 ? sizeof(sockaddr_in) : sizeof(sockaddr_in6);
+}
+
 void C4NetIO::EndpointAddress::SetPort(uint16_t port)
 {
 	switch (gen.sa_family)
@@ -1195,7 +1200,7 @@ bool C4NetIOTCP::Connect(const C4NetIO::
 #endif
 
 	// connect (async)
-	if (::connect(nsock, &addr, sizeof addr) == SOCKET_ERROR)
+	if (::connect(nsock, &addr, addr.GetAddrLen()) == SOCKET_ERROR)
 	{
 		if (!HaveWouldBlockError()) // expected
 		{
@@ -1368,7 +1373,7 @@ C4NetIOTCP::Peer *C4NetIOTCP::Accept(SOC
 	addr_t caddr = ConnectAddr;
 
 	// accept incoming connection?
-	C4NetIO::addr_t addr; socklen_t iAddrSize = sizeof addr;
+	C4NetIO::addr_t addr; socklen_t iAddrSize = addr.GetAddrLen();
 	if (nsock == INVALID_SOCKET)
 	{
 		// accept from listener
@@ -1497,7 +1502,7 @@ bool C4NetIOTCP::Listen(uint16_t inListe
 	// bind listen socket
 	addr_t addr = addr_t::Any;
 	addr.SetPort(inListenPort);
-	if (::bind(lsock, &addr, sizeof(addr)) == SOCKET_ERROR)
+	if (::bind(lsock, &addr, addr.GetAddrLen()) == SOCKET_ERROR)
 	{
 		SetError("socket bind failed", true);
 		closesocket(lsock); lsock = INVALID_SOCKET;
@@ -2122,7 +2127,7 @@ bool C4NetIOSimpleUDP::Send(const C4NetI
 	// send it
 	C4NetIO::addr_t addr = rPacket.getAddr();
 	if (::sendto(sock, getBufPtr<char>(rPacket), rPacket.getSize(), 0,
-	             &addr, sizeof(addr))
+	             &addr, addr.GetAddrLen())
 	    != int(rPacket.getSize()) &&
 	    !HaveWouldBlockError())
 	{
