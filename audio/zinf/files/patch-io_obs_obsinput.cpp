--- io/obs/obsinput.cpp.orig	2003-09-16 17:35:02 UTC
+++ io/obs/obsinput.cpp
@@ -198,6 +198,7 @@ Error ObsInput::Open(void)
 
     m_pSin = (struct sockaddr_in *)malloc(sizeof(struct sockaddr_in));
     assert(m_pSin);
+    (void) memset(m_pSin, 0, sizeof(*m_pSin));
 
     iReuse = 1;
     m_pSin->sin_family = AF_INET;
@@ -218,6 +219,7 @@ Error ObsInput::Open(void)
     else
         m_pSin->sin_addr.s_addr = htonl(INADDR_ANY);
 
+    (void) memset(&sMreq, 0, sizeof(sMreq));
     sMreq.imr_multiaddr.s_addr = inet_addr(szAddr);
     sMreq.imr_interface.s_addr = htonl(INADDR_ANY);
     if (IN_MULTICAST(ntohl(sMreq.imr_multiaddr.s_addr)))
