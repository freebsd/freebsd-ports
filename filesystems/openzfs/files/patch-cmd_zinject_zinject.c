--- cmd/zinject/zinject.c.orig	2025-03-29 23:43:40 UTC
+++ cmd/zinject/zinject.c
@@ -453,7 +453,8 @@ print_data_handler(int id, const char *pool, zinject_r
 
 
 	(void) printf("%3d  %-15s  %-6llu  %-6llu  %-8s  %-3d  0x%02x  %-15s  "
-	    "%6lu  %6lu\n", id, pool, (u_longlong_t)record->zi_objset,
+	    "%6" PRIu64 "  %6" PRIu64 "\n", id, pool,
+	    (u_longlong_t)record->zi_objset,
 	    (u_longlong_t)record->zi_object, type_to_name(record->zi_type),
 	    record->zi_level, record->zi_dvas, rangebuf,
 	    record->zi_match_count, record->zi_inject_count);
@@ -490,7 +491,8 @@ print_device_handler(int id, const char *pool, zinject
 	    (((double)record->zi_freq) / ZI_PERCENTAGE_MAX) * 100.0f;
 
 	(void) printf("%3d  %-15s  %llx  %-5s  %-10s  %8.4f%%  "
-	    "%6lu  %6lu\n", id, pool, (u_longlong_t)record->zi_guid,
+	    "%6" PRIu64 "  %6" PRIu64 "\n", id, pool,
+	    (u_longlong_t)record->zi_guid,
 	    iotype_to_str(record->zi_iotype), err_to_str(record->zi_error),
 	    freq, record->zi_match_count, record->zi_inject_count);
 
@@ -525,7 +527,8 @@ print_delay_handler(int id, const char *pool, zinject_
 	    (((double)record->zi_freq) / ZI_PERCENTAGE_MAX) * 100.0f;
 
 	(void) printf("%3d  %-15s  %llx  %10llu  %5llu  %8.4f%%  "
-	    "%6lu  %6lu\n", id, pool, (u_longlong_t)record->zi_guid,
+	    "%6" PRIu64 "  %6" PRIu64 "\n", id, pool,
+	    (u_longlong_t)record->zi_guid,
 	    (u_longlong_t)NSEC2MSEC(record->zi_timer),
 	    (u_longlong_t)record->zi_nlanes,
 	    freq, record->zi_match_count, record->zi_inject_count);
