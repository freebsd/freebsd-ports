--- src/include/distributed/master_metadata_utility.h.orig	2016-03-25 21:45:35 UTC
+++ src/include/distributed/master_metadata_utility.h
@@ -22,7 +22,7 @@
 
 
 /* total number of hash tokens (2^32) */
-#define HASH_TOKEN_COUNT INT64CONST(4294967296UL)
+#define HASH_TOKEN_COUNT INT64CONST(4294967296)
 
 /* In-memory representation of a typed tuple in pg_dist_shard. */
 typedef struct ShardInterval
