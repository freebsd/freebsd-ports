--- storage/rocksdb/rdb_datadic.h.orig	2017-09-25 06:33:26 UTC
+++ storage/rocksdb/rdb_datadic.h
@@ -16,6 +16,7 @@
 #pragma once
 
 /* C++ standard header files */
+#include <cstdlib>
 #include <algorithm>
 #include <atomic>
 #include <map>
