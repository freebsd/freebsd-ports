--- src/java/org/apache/cassandra/db/commitlog/MemoryMappedSegment.java.orig	2019-10-24 16:42:10 UTC
+++ src/java/org/apache/cassandra/db/commitlog/MemoryMappedSegment.java
@@ -90,7 +90,7 @@ public class MemoryMappedSegment extends CommitLogSegm
         {
             throw new FSWriteError(e, getPath());
         }
-        NativeLibrary.trySkipCache(fd, startMarker, nextMarker, logFile.getAbsolutePath());
+//        NativeLibrary.trySkipCache(fd, startMarker, nextMarker, logFile.getAbsolutePath());
     }
 
     @Override
