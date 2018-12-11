--- dnsperf.c.orig	2015-12-16 00:46:49 UTC
+++ dnsperf.c
@@ -52,8 +52,10 @@
 
 #define ISC_BUFFER_USEINLINE
 
+#include <isc/boolean.h>
 #include <isc/buffer.h>
 #include <isc/file.h>
+#include <isc/int.h>
 #include <isc/list.h>
 #include <isc/mem.h>
 #include <isc/netaddr.h>
@@ -280,16 +282,16 @@ print_statistics(const config_t *config, const times_t
 
 	printf("Statistics:\n\n");
 
-	printf("  %s sent:         %" ISC_PRINT_QUADFORMAT "u\n",
+	printf("  %s sent:         %" PRIu64 "\n",
                units, stats->num_sent);
-	printf("  %s completed:    %" ISC_PRINT_QUADFORMAT "u (%.2lf%%)\n",
+	printf("  %s completed:    %" PRIu64 " (%.2lf%%)\n",
 	       units, stats->num_completed,
 	       SAFE_DIV(100.0 * stats->num_completed, stats->num_sent));
-	printf("  %s lost:         %" ISC_PRINT_QUADFORMAT "u (%.2lf%%)\n",
+	printf("  %s lost:         %" PRIu64 " (%.2lf%%)\n",
 	       units, stats->num_timedout,
 	       SAFE_DIV(100.0 * stats->num_timedout, stats->num_sent));
 	if (stats->num_interrupted > 0)
-		printf("  %s interrupted:  %" ISC_PRINT_QUADFORMAT "u "
+		printf("  %s interrupted:  %" PRIu64 " "
                        "(%.2lf%%)\n",
 		       units, stats->num_interrupted,
 		       SAFE_DIV(100.0 * stats->num_interrupted,
@@ -305,7 +307,7 @@ print_statistics(const config_t *config, const times_t
 			first_rcode = ISC_FALSE;
 		else
 			printf(", ");
-		printf("%s %" ISC_PRINT_QUADFORMAT "u (%.2lf%%)",
+		printf("%s %" PRIu64 " (%.2lf%%)",
 		       perf_dns_rcode_strings[i], stats->rcodecounts[i],
 		       (stats->rcodecounts[i] * 100.0) / stats->num_completed);
 	}
