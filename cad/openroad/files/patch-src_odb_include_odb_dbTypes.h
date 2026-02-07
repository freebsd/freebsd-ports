--- src/odb/include/odb/dbTypes.h.orig	2022-02-10 04:05:30 UTC
+++ src/odb/include/odb/dbTypes.h
@@ -34,6 +34,8 @@
 
 #include "odb.h"
 
+#include <sys/types.h> // int8_t
+
 namespace odb {
 
 ///
