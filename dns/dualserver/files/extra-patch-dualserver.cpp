--- dualserver.cpp.orig	Mon Dec 12 10:41:03 2005
+++ dualserver.cpp	Mon Dec 12 10:43:53 2005
@@ -349,8 +349,8 @@
 	else
 	{
 		req->dnsp.header.ancount = 0;
-		req->dnsp.header.rcode = 3;
-		req->dnsp.header.ra = 0;
+		req->dnsp.header.flags.rcode = 3;
+		req->dnsp.header.flags.ra = 0;
 	}
 
 	if (cfig->servers[0])
@@ -364,8 +364,8 @@
 		req->dnsp.header.adcount = 0;
 	}
 
-	req->dnsp.header.qr = 1;
-	req->dnsp.header.aa = 1;
+	req->dnsp.header.flags.qr = 1;
+	req->dnsp.header.flags.aa = 1;
 
 	char *raw = req->dnsp.data;
 
@@ -495,7 +495,7 @@
 	if (!cfig->servers[0])
 		glocal(cfig);
 
-	if (ntohs(req->dnsp.header.qdcount) == 1 && ntohs(req->dnsp.header.opcode) == 0)
+	if (ntohs(req->dnsp.header.qdcount) == 1 && ntohs(req->dnsp.header.flags.opcode) == 0)
 	{
 		char *raw = req->dnsp.data;
 		strcpy(req->raw_query, raw);
@@ -619,7 +619,7 @@
 
 WORD fdnmess(data5 *req, data2 *cfig)
 {
-	if (!req->dnsp.header.rd)
+	if (!req->dnsp.header.flags.rd)
 		return 0;
 
 	if (!cfig->dns[0])
@@ -679,10 +679,10 @@
 	else
 	{
 		req->dnsp.header.ancount = 0;
-		req->dnsp.header.rcode = 3;
-		req->dnsp.header.ra = 0;
-		req->dnsp.header.qr = 1;
-		req->dnsp.header.aa = 0;
+		req->dnsp.header.flags.rcode = 3;
+		req->dnsp.header.flags.ra = 0;
+		req->dnsp.header.flags.qr = 1;
+		req->dnsp.header.flags.aa = 0;
 		req->BytesReady = req->BytesRecd;
 		return 0;
 	}
@@ -754,7 +754,7 @@
 	if (!found)
 		req->BytesReady = 0;
 
-	req->dnsp.header.aa = 0;
+	req->dnsp.header.flags.aa = 0;
 	return req->BytesReady;
 }
 
