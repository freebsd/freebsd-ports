--- src/java/org/apache/cassandra/config/Config.java.orig	2019-10-24 16:42:10 UTC
+++ src/java/org/apache/cassandra/config/Config.java
@@ -260,7 +260,7 @@ public class Config
     public volatile int key_cache_save_period = 14400;
     public volatile int key_cache_keys_to_save = Integer.MAX_VALUE;
 
-    public String row_cache_class_name = "org.apache.cassandra.cache.OHCProvider";
+    public String row_cache_class_name = "org.apache.cassandra.cache.SerializingCacheProvider";
     public long row_cache_size_in_mb = 0;
     public volatile int row_cache_save_period = 0;
     public volatile int row_cache_keys_to_save = Integer.MAX_VALUE;
