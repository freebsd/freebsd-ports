--- hadoop-common-project/hadoop-common/src/main/java/org/apache/hadoop/util/StringUtils.java.orig	2014-06-21 09:40:06.000000000 +0400
+++ hadoop-common-project/hadoop-common/src/main/java/org/apache/hadoop/util/StringUtils.java	2014-07-18 20:37:46.000000000 +0400
@@ -626,7 +626,7 @@ public class StringUtils {
         )
       );
 
-    if (SystemUtils.IS_OS_UNIX) {
+    if (true) {
       try {
         SignalLogger.INSTANCE.register(LOG);
       } catch (Throwable t) {
