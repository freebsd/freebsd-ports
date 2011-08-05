--- tests/mem_functions.cc.orig	2011-08-05 09:20:08.000000000 +0800
+++ tests/mem_functions.cc	2011-08-05 09:29:52.000000000 +0800
@@ -3629,7 +3629,7 @@ static test_return_t pre_nonblock_binary
     memcached_behavior_set(memc, MEMCACHED_BEHAVIOR_NO_BLOCK, 0);
     test_compare(MEMCACHED_SUCCESS,
                  memcached_behavior_set(memc, MEMCACHED_BEHAVIOR_BINARY_PROTOCOL, 1));
-    test_compare(1UL, memcached_behavior_get(memc, MEMCACHED_BEHAVIOR_BINARY_PROTOCOL));
+    test_compare(1UL, (unsigned long)memcached_behavior_get(memc, MEMCACHED_BEHAVIOR_BINARY_PROTOCOL));
   }
   else
   {
@@ -4401,7 +4401,7 @@ static test_return_t connection_pool_tes
     uint64_t number_value;
     test_compare(MEMCACHED_SUCCESS,
                  memcached_increment(mmc[x], key, keylen, 1, &number_value));
-    test_compare(number_value, (x+1));
+    test_compare(number_value, (uint64_t)(x+1));
   }
 
   // Release them..
@@ -4951,7 +4951,7 @@ static test_return_t ketama_compatibilit
   test_compare(MEMCACHED_SUCCESS,
                memcached_behavior_set(memc, MEMCACHED_BEHAVIOR_KETAMA_WEIGHTED, 1));
 
-  test_compare(1UL, memcached_behavior_get(memc, MEMCACHED_BEHAVIOR_KETAMA_WEIGHTED));
+  test_compare(1UL, (unsigned long)memcached_behavior_get(memc, MEMCACHED_BEHAVIOR_KETAMA_WEIGHTED));
 
   test_compare(MEMCACHED_SUCCESS, memcached_behavior_set_distribution(memc, MEMCACHED_DISTRIBUTION_CONSISTENT_KETAMA));
   test_compare(MEMCACHED_DISTRIBUTION_CONSISTENT_KETAMA, memcached_behavior_get_distribution(memc));
@@ -5882,7 +5882,7 @@ static test_return_t regression_bug_6554
 
     test_compare(MEMCACHED_SUCCESS, rc);
     test_true(value);
-    test_compare(100UL, value_length);
+    test_compare(100UL, (unsigned long)value_length);
     free(value);
   }
 
