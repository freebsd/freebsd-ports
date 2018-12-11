--- resperf.c.orig	2015-12-16 00:46:50 UTC
+++ resperf.c
@@ -46,8 +46,10 @@
 
 #include <sys/time.h>
 
+#include <isc/boolean.h>
 #include <isc/buffer.h>
 #include <isc/file.h>
+#include <isc/int.h>
 #include <isc/list.h>
 #include <isc/mem.h>
 #include <isc/print.h>
@@ -389,11 +391,11 @@ print_statistics(void) {
 
 	printf("\nStatistics:\n\n");
 
-	printf("  Queries sent:         %" ISC_PRINT_QUADFORMAT "u\n",
+	printf("  Queries sent:         %" PRIu64 "\n",
                num_queries_sent);
-	printf("  Queries completed:    %" ISC_PRINT_QUADFORMAT "u\n",
+	printf("  Queries completed:    %" PRIu64 "\n",
                num_responses_received);
-	printf("  Queries lost:         %" ISC_PRINT_QUADFORMAT "u\n",
+	printf("  Queries lost:         %" PRIu64 "\n",
 	       num_queries_sent - num_responses_received);
 	printf("  Response codes:       ");
 	first_rcode = ISC_TRUE;
@@ -404,7 +406,7 @@ print_statistics(void) {
 			first_rcode = ISC_FALSE;
 		else
 			printf(", ");
-		printf("%s %" ISC_PRINT_QUADFORMAT "u (%.2lf%%)",
+		printf("%s %" PRIu64 " (%.2lf%%)",
 		       perf_dns_rcode_strings[i], rcodecounts[i],
 		       (rcodecounts[i] * 100.0) / num_responses_received);
 	}
