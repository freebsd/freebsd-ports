--- src/java/org/apache/cassandra/config/Config.java.orig	2024-10-12 12:40:43 UTC
+++ src/java/org/apache/cassandra/config/Config.java
@@ -460,7 +460,7 @@ public class Config
     @Replaces(oldName = "key_cache_save_period", converter = Converters.SECONDS_CUSTOM_DURATION)
     public volatile DurationSpec.IntSecondsBound key_cache_save_period = new DurationSpec.IntSecondsBound("4h");
 
-    public String row_cache_class_name = "org.apache.cassandra.cache.OHCProvider";
+    public String row_cache_class_name = "org.apache.cassandra.cache.SerializingCacheProvider";
     @Replaces(oldName = "row_cache_size_in_mb", converter = Converters.MEBIBYTES_DATA_STORAGE_LONG, deprecated = true)
     public DataStorageSpec.LongMebibytesBound row_cache_size = new DataStorageSpec.LongMebibytesBound("0MiB");
     @Replaces(oldName = "row_cache_save_period", converter = Converters.SECONDS_CUSTOM_DURATION)
