--- hadoop-common-project/hadoop-common/src/main/java/org/apache/hadoop/io/nativeio/SharedFileDescriptorFactory.java.orig	2014-06-21 09:40:10.000000000 +0400
+++ hadoop-common-project/hadoop-common/src/main/java/org/apache/hadoop/io/nativeio/SharedFileDescriptorFactory.java	2014-07-04 13:49:25.000000000 +0400
@@ -53,7 +53,7 @@
     if (!NativeIO.isAvailable()) {
       return "NativeIO is not available.";
     }
-    if (!SystemUtils.IS_OS_UNIX) {
+    if (false) {
       return "The OS is not UNIX.";
     }
     return null;
