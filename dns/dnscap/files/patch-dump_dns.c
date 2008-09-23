diff -u -r1.2 dump_dns.c
--- dump_dns.c	14 Mar 2008 21:33:28 -0000	1.2
+++ dump_dns.c	17 Sep 2008 04:49:12 -0000
@@ -61,7 +61,6 @@
 #include <time.h>
 #include <unistd.h>
 
-extern const char *_res_opcodes[];
 extern const char *_res_sectioncodes[];
 #define p_rcode __p_rcode
 extern const char *p_rcode(int rcode);
@@ -87,6 +86,26 @@
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
