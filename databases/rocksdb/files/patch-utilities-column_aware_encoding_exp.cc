--- utilities/column_aware_encoding_exp.cc.orig	2016-12-09 20:59:51 UTC
+++ utilities/column_aware_encoding_exp.cc
@@ -8,6 +8,7 @@
 #endif
 
 #include <cstdio>
+#include <cstdlib>
 
 #ifndef ROCKSDB_LITE
 #ifdef GFLAGS
