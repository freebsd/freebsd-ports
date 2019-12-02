udpnet.cpp:61:6: error: no viable conversion from '__bind<int &, sockaddr *, unsigned long>' to 'int'
        int rc = bind (m_Socket, (struct sockaddr *) &MyAddress, sizeof(MyAddress));
            ^    ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

--- simulation/udpnet.cpp.orig	2019-12-02 12:38:14 UTC
+++ simulation/udpnet.cpp
@@ -58,7 +58,7 @@ CUDPNet::CUDPNet(unsigned int port)
 	MyAddress.sin_addr.s_addr = htonl(INADDR_ANY);
 	MyAddress.sin_port = htons(port);
 
-	int rc = bind (m_Socket, (struct sockaddr *) &MyAddress, sizeof(MyAddress));
+	int rc = ::bind (m_Socket, (struct sockaddr *) &MyAddress, sizeof(MyAddress));
 	if(rc < 0)
 	{
 		printf("cannot bind port number %d \n", port);
