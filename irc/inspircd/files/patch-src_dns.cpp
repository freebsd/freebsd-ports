--- src/dns.cpp.orig	2012-05-15 21:45:31.840274636 -0500
+++ src/dns.cpp	2012-05-15 21:45:58.653278686 -0500
@@ -38,6 +49,8 @@
 #include "configreader.h"
 #include "socket.h"
 
+#define DN_COMP_BITMASK	0xC000		/* highest 6 bits in a DN label header */
+
 /** Masks to mask off the responses we get from the DNSRequest methods
  */
 enum QueryInfo
@@ -98,7 +111,7 @@
 
 	DNSRequest(DNS* dns, int id, const std::string &original);
 	~DNSRequest();
-	DNSInfo ResultIsReady(DNSHeader &h, int length);
+	DNSInfo ResultIsReady(DNSHeader &h, unsigned length);
 	int SendRequests(const DNSHeader *header, const int length, QueryType qt);
 };
 
@@ -161,7 +174,10 @@
 /* Allocate the processing buffer */
 DNSRequest::DNSRequest(DNS* dns, int rid, const std::string &original) : dnsobj(dns)
 {
-	res = new unsigned char[512];
+	/* hardening against overflow here:  make our work buffer twice the theoretical
+	 * maximum size so that hostile input doesn't screw us over.
+	 */
+	res = new unsigned char[sizeof(DNSHeader) * 2];
 	*res = 0;
 	orig = original;
 	RequestTimeout* RT = new RequestTimeout(ServerInstance->Config->dns_timeout ? ServerInstance->Config->dns_timeout : 5, this, rid);
@@ -688,11 +704,11 @@
 }
 
 /** A result is ready, process it */
-DNSInfo DNSRequest::ResultIsReady(DNSHeader &header, int length)
+DNSInfo DNSRequest::ResultIsReady(DNSHeader &header, unsigned length)
 {
-	int i = 0;
+	unsigned i = 0, o;
 	int q = 0;
-	int curanswer, o;
+	int curanswer;
 	ResourceRecord rr;
  	unsigned short ptr;
 
@@ -755,7 +771,7 @@
 				else i += header.payload[i] + 1; /* skip length and label */
 			}
 		}
-		if (length - i < 10)
+		if (static_cast<int>(length - i) < 10)
 			return std::make_pair((unsigned char*)NULL,"Incorrectly sized DNS reply");
 
 		/* XXX: We actually initialise 'rr' here including its ttl field */
@@ -790,17 +806,37 @@
 
 	switch (rr.type)
 	{
+		/*
+		 * CNAME and PTR are compressed.  We need to decompress them.
+		 */
 		case DNS_QUERY_CNAME:
-			/* CNAME and PTR have the same processing code */
 		case DNS_QUERY_PTR:
+		{
+			unsigned short lowest_pos = length;
 			o = 0;
 			q = 0;
 			while (q == 0 && i < length && o + 256 < 1023)
 			{
+				/* DN label found (byte over 63) */
 				if (header.payload[i] > 63)
 				{
 					memcpy(&ptr,&header.payload[i],2);
-					i = ntohs(ptr) - 0xC000 - 12;
+
+					i = ntohs(ptr);
+
+					/* check that highest two bits are set. if not, we've been had */
+					if ((i & DN_COMP_BITMASK) != DN_COMP_BITMASK)
+						return std::make_pair((unsigned char *) NULL, "DN label decompression header is bogus");
+
+					/* mask away the two highest bits. */
+					i &= ~DN_COMP_BITMASK;
+
+					/* and decrease length by 12 bytes. */
+					i -= 12;
+
+					if (i >= lowest_pos)
+						return std::make_pair((unsigned char *) NULL, "Invalid decompression pointer");
+					lowest_pos = i;
 				}
 				else
 				{
@@ -813,25 +849,35 @@
 						res[o] = 0;
 						if (o != 0)
 							res[o++] = '.';
-						memcpy(&res[o],&header.payload[i + 1],header.payload[i]);
+
+						if (o + header.payload[i] > sizeof(DNSHeader))
+							return std::make_pair((unsigned char *) NULL, "DN label decompression is impossible -- malformed/hostile packet?");
+
+						memcpy(&res[o], &header.payload[i + 1], header.payload[i]);
 						o += header.payload[i];
 						i += header.payload[i] + 1;
 					}
 				}
 			}
 			res[o] = 0;
+		}
 		break;
 		case DNS_QUERY_AAAA:
+			if (rr.rdlength != sizeof(struct in6_addr))
+				return std::make_pair((unsigned char *) NULL, "rr.rdlength is larger than 16 bytes for an ipv6 entry -- malformed/hostile packet?");
+
 			memcpy(res,&header.payload[i],rr.rdlength);
 			res[rr.rdlength] = 0;
 		break;
 		case DNS_QUERY_A:
+			if (rr.rdlength != sizeof(struct in_addr))
+				return std::make_pair((unsigned char *) NULL, "rr.rdlength is larger than 4 bytes for an ipv4 entry -- malformed/hostile packet?");
+
 			memcpy(res,&header.payload[i],rr.rdlength);
 			res[rr.rdlength] = 0;
 		break;
 		default:
-			memcpy(res,&header.payload[i],rr.rdlength);
-			res[rr.rdlength] = 0;
+			return std::make_pair((unsigned char *) NULL, "don't know how to handle undefined type (" + ConvToStr(rr.type) + ") -- rejecting");
 		break;
 	}
 	return std::make_pair(res,"No error");
