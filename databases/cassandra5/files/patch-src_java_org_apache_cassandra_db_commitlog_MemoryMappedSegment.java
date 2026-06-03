--- src/java/org/apache/cassandra/db/commitlog/MemoryMappedSegment.java.orig	2024-10-12 12:40:42 UTC
+++ src/java/org/apache/cassandra/db/commitlog/MemoryMappedSegment.java
@@ -96,7 +96,7 @@ public class MemoryMappedSegment extends CommitLogSegm
         {
             throw new FSWriteError(e, getPath());
         }
-        NativeLibrary.trySkipCache(fd, startMarker, nextMarker, logFile.absolutePath());
+//        NativeLibrary.trySkipCache(fd, startMarker, nextMarker, logFile.absolutePath());
     }
 
     @Override
