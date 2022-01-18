--- src/java/org/apache/cassandra/tools/nodetool/Status.java.orig	2021-07-01 14:37:50 UTC
+++ src/java/org/apache/cassandra/tools/nodetool/Status.java
@@ -190,7 +190,7 @@ public class Status extends NodeToolCmd
             String addressPlaceholder = String.format("%%-%ds  ", maxAddressLength);
             buf.append("%s%s  ");                         // status
             buf.append(addressPlaceholder);               // address
-            buf.append("%-9s  ");                         // load
+            buf.append("%-11s  ");                        // load (support up to "xxxx.xxx XiB")
             if (!isTokenPerNode)
                 buf.append("%-11s  ");                     // "Tokens"
             if (hasEffectiveOwns)
