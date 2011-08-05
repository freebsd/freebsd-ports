--- tests/replication.cc.orig	2011-08-05 09:22:41.000000000 +0800
+++ tests/replication.cc	2011-08-05 09:23:16.000000000 +0800
@@ -249,10 +249,10 @@ test_return_t replication_delete_test(me
 
   // Make one copy
   test_compare(MEMCACHED_SUCCESS, memcached_behavior_set(memc_replicated, MEMCACHED_BEHAVIOR_NUMBER_OF_REPLICAS, 1UL));
-  test_compare(1UL, memcached_behavior_get(memc_replicated, MEMCACHED_BEHAVIOR_NUMBER_OF_REPLICAS));
+  test_compare(1UL, (unsigned long)memcached_behavior_get(memc_replicated, MEMCACHED_BEHAVIOR_NUMBER_OF_REPLICAS));
 
   test_compare(MEMCACHED_SUCCESS, memcached_behavior_set(memc_not_replicate, MEMCACHED_BEHAVIOR_NUMBER_OF_REPLICAS, 0UL));
-  test_compare(0UL, memcached_behavior_get(memc_not_replicate, MEMCACHED_BEHAVIOR_NUMBER_OF_REPLICAS));
+  test_compare(0UL, (unsigned long)memcached_behavior_get(memc_not_replicate, MEMCACHED_BEHAVIOR_NUMBER_OF_REPLICAS));
 
   for (size_t x= 0; x < test_array_length(keys); ++x)
   {
