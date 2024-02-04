--- src/a3m_compress.cpp.orig	2024-02-04 09:18:03 UTC
+++ src/a3m_compress.cpp
@@ -12,6 +12,9 @@
 #include <omp.h>
 #endif
 
+#include <functional> // for std::ptr_fun
+
+
 int compressed_a3m::compress_a3m(std::istream* input,
     ffindex_index_t* ffindex_sequence_database_index,
     char* ffindex_sequence_database_data, std::ostream* output) {
