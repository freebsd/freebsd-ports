--- src/java/org/apache/cassandra/config/Config.java.orig	2018-03-06 21:16:18 UTC
+++ src/java/org/apache/cassandra/config/Config.java
@@ -252,7 +252,7 @@ public class Config
     public volatile int key_cache_save_period = 14400;
     public volatile int key_cache_keys_to_save = Integer.MAX_VALUE;
 
-    public String row_cache_class_name = "org.apache.cassandra.cache.OHCProvider";
+    public String row_cache_class_name = "org.apache.cassandra.cache.SerializingCacheProvider";
     public long row_cache_size_in_mb = 0;
     public volatile int row_cache_save_period = 0;
     public volatile int row_cache_keys_to_save = Integer.MAX_VALUE;
