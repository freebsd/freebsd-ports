--- ext/io/event/selector/selector.h.orig	2023-10-30 05:01:49 UTC
+++ ext/io/event/selector/selector.h
@@ -33,6 +33,7 @@
 #define RUBY_FIBER_SCHEDULER_VERSION 1
 #endif
 
+#include <sys/wait.h>
 #include <time.h>
 
 enum IO_Event {
