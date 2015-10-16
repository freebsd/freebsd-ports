--- hbase-client/src/main/java/org/apache/hadoop/hbase/util/PoolMap.java.orig	2014-12-16 06:16:53 UTC
+++ hbase-client/src/main/java/org/apache/hadoop/hbase/util/PoolMap.java
@@ -93,14 +93,6 @@ public class PoolMap<K, V> implements Ma
     return null;
   }
 
-  /**
-   * @deprecated Will be removed for Java 8, use {@link #removeValue} instead
-   */
-  @Deprecated
-  public boolean remove(K key, V value) {
-    return removeValue(key, value);
-  }
-
   public boolean removeValue(K key, V value) {
     Pool<V> pool = pools.get(key);
     boolean res = false;
