--- simpleperf/event_attr.cpp.orig	2015-08-12 01:49:40 UTC
+++ simpleperf/event_attr.cpp
@@ -18,6 +18,7 @@
 
 #include <inttypes.h>
 #include <stdio.h>
+#include <string.h> // memset
 #include <string>
 #include <unordered_map>
 
