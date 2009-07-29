diff -ur bind-9.6.1/bin/named/update.c bind-9.6.1-P1/bin/named/update.c
--- bin/named/update.c	2009-04-30 00:03:37.000000000 -0700
+++ bin/named/update.c	2009-07-28 07:18:08.000000000 -0700
@@ -979,7 +979,11 @@
 			if (type == dns_rdatatype_rrsig ||
 			    type == dns_rdatatype_sig)
 				covers = dns_rdata_covers(&t->rdata);
-			else
+			else if (type == dns_rdatatype_any) {
+				dns_db_detachnode(db, &node);
+				dns_diff_clear(&trash);
+				return (DNS_R_NXRRSET);
+			} else
 				covers = 0;
 
 			/*
