--- src/java/org/apache/cassandra/config/Config.java.orig	2022-05-06 16:40:06 UTC
+++ src/java/org/apache/cassandra/config/Config.java
@@ -304,7 +304,7 @@ public class Config
     public volatile int key_cache_save_period = 14400;
     public volatile int key_cache_keys_to_save = Integer.MAX_VALUE;
 
-    public String row_cache_class_name = "org.apache.cassandra.cache.OHCProvider";
+    public String row_cache_class_name = "org.apache.cassandra.cache.SerializingCacheProvider";
     public long row_cache_size_in_mb = 0;
     public volatile int row_cache_save_period = 0;
     public volatile int row_cache_keys_to_save = Integer.MAX_VALUE;
