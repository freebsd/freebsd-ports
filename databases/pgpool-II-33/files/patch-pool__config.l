--- pool_config.l.orig	2018-02-22 11:24:41 UTC
+++ pool_config.l
@@ -2871,7 +2871,7 @@ int pool_get_config(char *confpath, POOL
 			pool_config->backend_desc->num_backends = local_num_backends;
 
 	pool_debug("num_backends: %d total_weight: %f",
-			   pool_config->backend_desc->num_backends, total_weight);
+			  (long) pool_config->backend_desc->num_backends, total_weight);
 	/*
 	 * Normalize load balancing weights. What we are doing here is,
 	 * assign 0 to RAND_MAX to each backend's weight according to the
