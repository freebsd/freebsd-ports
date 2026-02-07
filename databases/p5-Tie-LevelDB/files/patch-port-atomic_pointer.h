--- port/atomic_pointer.h.orig	2019-08-25 00:44:43 UTC
+++ port/atomic_pointer.h
@@ -21,7 +21,7 @@
 
 #include <stdint.h>
 #ifdef LEVELDB_CSTDATOMIC_PRESENT
-#include <cstdatomic>
+#include <atomic>
 #endif
 #ifdef OS_WIN
 #include <windows.h>
