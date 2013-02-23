--- ./examples/hash_usage.c.orig	2013-02-22 17:00:53.679654885 +0000
+++ ./examples/hash_usage.c	2013-02-22 17:02:43.078657742 +0000
@@ -36,8 +36,8 @@
 	cfuhash_set_flag(hash, CFUHASH_FROZEN_UNTIL_GROWS);
 
 	for (i = 0; i < 32; i++) {
-		sprintf(list[i][0], "test_var%d", i);
-		sprintf(list[i][1], "value%d", i);
+		sprintf(list[i][0], "test_var%zd", i);
+		sprintf(list[i][1], "value%zd", i);
 	}
 	
 	cfuhash_put(hash, "var1", "value1");
@@ -58,7 +58,7 @@
 	printf("got var2='%s'\n", val);
 	printf("var4 %s\n", cfuhash_exists(hash, "var4") ? "exists" : "does NOT exist!!!");
 
-	printf("%d entries, %d buckets used out of %d\n", cfuhash_num_entries(hash), cfuhash_num_buckets_used(hash), cfuhash_num_buckets(hash));
+	printf("%zd entries, %zd buckets used out of %zd\n", cfuhash_num_entries(hash), cfuhash_num_buckets_used(hash), cfuhash_num_buckets(hash));
 
 	cfuhash_pretty_print(hash, stdout);
 	
@@ -69,7 +69,7 @@
 		size_t num_buckets = cfuhash_num_buckets(hash);
 		size_t num_entries = cfuhash_num_entries(hash);
 		cfuhash_put(hash, list[i][0], list[i][1]);
-		printf("%d entries, %d buckets used out of %d (%.2f)\n", num_entries, used, num_buckets, (float)num_entries/(float)num_buckets);
+		printf("%zd entries, %zd buckets used out of %zd (%.2f)\n", num_entries, used, num_buckets, (float)num_entries/(float)num_buckets);
 
 	}
 
@@ -82,7 +82,7 @@
 		
 		keys = (char **)cfuhash_keys_data(hash, &key_count, &key_sizes, 0);
 
-		printf("\n\nkeys (%u):\n", key_count);
+		printf("\n\nkeys (%zu):\n", key_count);
 		for (i = 0; i < key_count; i++) {
 			printf("\t%s\n", keys[i]);
 			free(keys[i]);
@@ -92,7 +92,7 @@
 	}
 
 	cfuhash_clear(hash);
-	printf("%d entries, %d buckets used out of %d\n", cfuhash_num_entries(hash), cfuhash_num_buckets_used(hash), cfuhash_num_buckets(hash));
+	printf("%zd entries, %zd buckets used out of %zd\n", cfuhash_num_entries(hash), cfuhash_num_buckets_used(hash), cfuhash_num_buckets(hash));
 
 	cfuhash_destroy(hash);
 
