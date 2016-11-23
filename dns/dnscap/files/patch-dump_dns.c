--- dump_dns.c.orig	2011-03-11 21:38:56 UTC
+++ dump_dns.c
@@ -60,7 +60,6 @@ static const char rcsid[] = "$Id: dump_d
 #include <time.h>
 #include <unistd.h>
 
-extern const char *_res_opcodes[];
 extern const char *_res_sectioncodes[];
 #define p_rcode __p_rcode
 extern const char *p_rcode(int rcode);
@@ -86,6 +85,26 @@ static void dump_dns_rr(ns_msg *, ns_rr 
 	(cp) += INT32SZ; \
 } while (0)
 
+
+const char *_res_opcodes[] = {
+        "QUERY",
+        "IQUERY",
+        "CQUERYM",
+        "CQUERYU",      /*%< experimental */
+        "NOTIFY",       /*%< experimental */
+        "UPDATE",
+        "6",
+        "7",
+        "8",
+        "9",
+        "10",
+        "11",
+        "12",
+        "13",
+        "ZONEINIT",
+        "ZONEREF",
+};
+
 #include "dump_dns.h"
 
 void
