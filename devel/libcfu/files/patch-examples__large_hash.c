--- ./examples/large_hash.c.orig	2013-02-22 17:03:12.957659394 +0000
+++ ./examples/large_hash.c	2013-02-22 17:03:58.328654728 +0000
@@ -113,8 +113,8 @@
 
 	cfutime_begin(time);
 	for (i = 0; i < num_tests; i++) {
-		sprintf(key, "%u", 15000000 - i);
-		sprintf(value, "value%d", i);
+		sprintf(key, "%zu", 15000000 - i);
+		sprintf(value, "value%zd", i);
 		cfuhash_put(hash, key, dup_str(value));
 	}
 	cfutime_end(time);
@@ -123,7 +123,7 @@
 	used = cfuhash_num_buckets_used(hash);
 	num_buckets = cfuhash_num_buckets(hash);
 	num_entries = cfuhash_num_entries(hash);
-	printf("%d entries, %d/%d buckets (%.2f%%), %.2f%% threshold check\n", num_entries, used, num_buckets, 100.0 * (float)used/(float)num_buckets, 100.0 * (float)num_entries/(float)num_buckets);
+	printf("%zd entries, %zd/%zd buckets (%.2f%%), %.2f%% threshold check\n", num_entries, used, num_buckets, 100.0 * (float)used/(float)num_buckets, 100.0 * (float)num_entries/(float)num_buckets);
 
 	cfuhash_destroy_with_free_fn(hash, free_data);	
 
@@ -138,7 +138,7 @@
 	argc = argc;
 	argv = argv;
 
-	printf("mutex is %d bytes\n", sizeof(pthread_mutex_t));
+	printf("mutex is %zd bytes\n", sizeof(pthread_mutex_t));
 
 	printf("default:\n");
 	time_it(NULL, &elapsed_time, num_tests);
