--- src/java/org/apache/cassandra/utils/NativeLibrary.java.orig	2020-01-30 17:34:32 UTC
+++ src/java/org/apache/cassandra/utils/NativeLibrary.java
@@ -141,7 +141,10 @@ public final class NativeLibrary
         else if (osName.contains("windows"))
             return WINDOWS;
 
-        logger.warn("the current operating system, {}, is unsupported by cassandra", osName);
+        if (osName.contains("bsd"))
+            logger.warn("the current operating system, {}, is fantastic, though not officially supported by cassandra", osName);
+        else
+            logger.warn("the current operating system, {}, is unsupported by cassandra", osName);
         if (osName.contains("aix"))
             return AIX;
         else
