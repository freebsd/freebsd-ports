--- dualserver.cpp.orig	Sun Apr 30 15:32:37 2006
+++ dualserver.cpp	Sun Apr 30 15:36:39 2006
@@ -463,8 +463,8 @@
 	if (!req->rtype)
 	{
 		req->dnsp.header.ancount = 0;
-		req->dnsp.header.rcode = 3;
-		req->dnsp.header.ra = 0;
+                req->dnsp.header.flags.rcode = 3;
+                req->dnsp.header.flags.ra = 0;
 	}
 
 	if (cfig->servers[0])
@@ -478,8 +478,8 @@
 		req->dnsp.header.adcount = 0;
 	}
 
-	req->dnsp.header.qr = 1;
-	req->dnsp.header.aa = 1;
+        req->dnsp.header.flags.qr = 1;
+        req->dnsp.header.flags.aa = 1;
 
 	char *raw = req->dnsp.data;
 
@@ -649,7 +649,7 @@
 	if (!cfig->dns[0])
 		getdnserv(cfig);
 
-	if (ntohs(req->dnsp.header.qdcount) == 1 && ntohs(req->dnsp.header.opcode) == 0)
+        if (ntohs(req->dnsp.header.qdcount) == 1 && ntohs(req->dnsp.header.flags.opcode) == 0)
 	{
 		char *raw = req->dnsp.data;
 		fQu(req->query, &req->dnsp, raw);
@@ -853,7 +853,7 @@
 
 WORD fdnmess(data5 *req, data2 *cfig)
 {
-	if (!req->dnsp.header.rd)
+        if (!req->dnsp.header.flags.rd)
 		return 0;
 
 	if (!cfig->dns[0])
@@ -923,10 +923,10 @@
 	else
 	{
 		req->dnsp.header.ancount = 0;
-		req->dnsp.header.rcode = 3;
-		req->dnsp.header.ra = 0;
-		req->dnsp.header.qr = 1;
-		req->dnsp.header.aa = 0;
+                req->dnsp.header.flags.rcode = 3;
+                req->dnsp.header.flags.ra = 0;
+                req->dnsp.header.flags.qr = 1;
+                req->dnsp.header.flags.aa = 0;
 		char *dp = req->dnsp.data;
 		dp += pQu(dp, req->query);
 		dp += pShort(dp, DNS_TYPE_A);
@@ -1106,7 +1106,7 @@
 	if (!found)
 		req->bytes = 0;
 
-	req->dnsp.header.aa = 0;
+        req->dnsp.header.flags.aa = 0;
 	return req->bytes;
 }
 
