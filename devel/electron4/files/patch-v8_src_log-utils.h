--- v8/src/log-utils.h.orig	2019-03-15 06:42:05 UTC
+++ v8/src/log-utils.h
@@ -15,6 +15,8 @@
 #include "src/flags.h"
 #include "src/ostreams.h"
 
+#include <stdarg.h>
+
 namespace v8 {
 namespace internal {
 
