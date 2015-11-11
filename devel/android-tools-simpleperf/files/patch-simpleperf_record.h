--- simpleperf/record.h.orig	2015-10-26 20:57:19 UTC
+++ simpleperf/record.h
@@ -20,6 +20,7 @@
 #include <stdio.h>
 #include <sys/types.h>
 
+#include <memory> // unique_ptr
 #include <queue>
 #include <string>
 #include <vector>
