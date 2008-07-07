--- main.cc.orig	2008-07-07 23:03:07.000000000 +0700
+++ main.cc	2008-07-07 23:05:51.000000000 +0700
@@ -286,7 +286,7 @@
 
     if (Sgets(buf, BUFSIZE, sock_req) == NULL) {
 	DMUCS_DEBUG((stderr, "Socket closed: %s\n", peer2buf(sock_req, buf)));
-	db->releaseCpu((unsigned int)sock_req);
+	db->releaseCpu(sock_req);
 	removeFd(sock_req);
 	return;
     }
