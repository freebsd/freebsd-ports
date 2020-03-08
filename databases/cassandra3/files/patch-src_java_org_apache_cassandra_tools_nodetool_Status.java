--- src/java/org/apache/cassandra/tools/nodetool/Status.java.orig	2019-12-18 11:47:59 UTC
+++ src/java/org/apache/cassandra/tools/nodetool/Status.java
@@ -188,7 +188,7 @@ public class Status extends NodeToolCmd
             String addressPlaceholder = String.format("%%-%ds  ", maxAddressLength);
             buf.append("%s%s  ");                         // status
             buf.append(addressPlaceholder);               // address
-            buf.append("%-9s  ");                         // load
+            buf.append("%-11s  ");                        // load (support up to "xxxx.xxx XiB")
             if (!isTokenPerNode)
                 buf.append("%-11s  ");                     // "Tokens"
             if (hasEffectiveOwns)
