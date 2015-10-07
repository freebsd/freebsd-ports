--- simpleperf/record.h.orig	2015-08-12 01:49:40 UTC
+++ simpleperf/record.h
@@ -19,6 +19,7 @@
 
 #include <sys/types.h>
 
+#include <memory> // unique_ptr
 #include <string>
 #include <vector>
 
