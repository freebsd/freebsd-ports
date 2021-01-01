--- base/trace_event/process_memory_dump.h.orig	2019-09-10 10:42:27 UTC
+++ base/trace_event/process_memory_dump.h
@@ -22,7 +22,7 @@
 
 // Define COUNT_RESIDENT_BYTES_SUPPORTED if platform supports counting of the
 // resident memory.
-#if !defined(OS_NACL)
+#if !defined(OS_NACL) && !defined(OS_BSD)
 #define COUNT_RESIDENT_BYTES_SUPPORTED
 #endif
 
