--- dualserver.cpp.orig	Mon Jun  5 16:08:44 2006
+++ dualserver.cpp	Mon Jun  5 16:09:14 2006
@@ -501,15 +501,15 @@
 	if (!req->rtype)
 	{
 		req->dnsp.header.ancount = 0;
-		req->dnsp.header.rcode = 3;
-		req->dnsp.header.ra = 0;
+		req->dnsp.header.flags.rcode = 3;
+		req->dnsp.header.flags.ra = 0;
 	}
 
 	req->dnsp.header.nscount = 0;
 	req->dnsp.header.adcount = 0;
-	req->dnsp.header.qr = 1;
-	req->dnsp.header.aa = 1;
-
+	req->dnsp.header.flags.qr = 1;
+	req->dnsp.header.flags.aa = 1;
+	
 	char *raw = req->dnsp.data;
 
 	for (int i = 1; i <= ntohs(req->dnsp.header.qdcount); i++)
@@ -701,7 +701,7 @@
 	time_t currentTime = time(NULL);
 	req->lease = cfig->lease;
 
-	if (ntohs(req->dnsp.header.qdcount) == 1 && ntohs(req->dnsp.header.opcode) == 0)
+	if (ntohs(req->dnsp.header.qdcount) == 1 && ntohs(req->dnsp.header.flags.opcode) == 0)
 	{
 		char *raw = req->dnsp.data;
 		raw += fQu(req->query, &req->dnsp, raw);
@@ -721,7 +721,7 @@
 		{
 			if (!checkLocal(req, cfig))
 			{
-				if (!req->dnsp.header.rd)
+				if (!req->dnsp.header.flags.rd)
 					return genMess(req, cfig);
 				else
 					return 0;
@@ -1127,7 +1127,7 @@
 	if (!found)
 		req->bytes = 0;
 
-	req->dnsp.header.aa = 0;
+	req->dnsp.header.flags.aa = 0;
 	return req->bytes;
 }
 
@@ -2216,7 +2216,7 @@
 
 			mess.header.xid = 6;
 			mess.header.qdcount = htons(1);
-			mess.header.rd = 1;
+			mess.header.flags.rd = 1;
 			char *raw = mess.data;
 			raw += pQu(raw, "1.0.0.127.in-addr.arpa");
 			raw += pShort(raw, DNS_TYPE_PTR);
