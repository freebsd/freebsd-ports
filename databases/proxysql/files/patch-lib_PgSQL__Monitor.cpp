--- lib/PgSQL_Monitor.cpp.orig	2025-11-08 02:06:01 UTC
+++ lib/PgSQL_Monitor.cpp
@@ -17,6 +17,11 @@
 #include <vector>
 #include <list>
 
+#ifdef __FreeBSD__
+#include <sys/limits.h>
+#define ULONG_LONG_MAX ULLONG_MAX
+#endif
+
 using std::function;
 using std::unique_ptr;
 using std::vector;
