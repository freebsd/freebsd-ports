--- io/obs/obsinput.cpp--	Thu Oct  5 17:17:33 2000
+++ io/obs/obsinput.cpp	Sun Jun  9 16:13:16 2002
@@ -193,6 +193,7 @@
 
     m_pSin = (struct sockaddr_in *)malloc(sizeof(struct sockaddr_in));
     assert(m_pSin);
+    (void) memset(m_pSin, 0, sizeof(*m_pSin));
 
     iReuse = 1;
     m_pSin->sin_family = AF_INET;
@@ -213,6 +214,7 @@
     else
         m_pSin->sin_addr.s_addr = htonl(INADDR_ANY);
 
+    (void) memset(&sMreq, 0, sizeof(sMreq));
     sMreq.imr_multiaddr.s_addr = inet_addr(szAddr);
     sMreq.imr_interface.s_addr = htonl(INADDR_ANY);
     if (IN_MULTICAST(ntohl(sMreq.imr_multiaddr.s_addr)))
