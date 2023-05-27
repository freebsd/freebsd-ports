--- src/objtools/blast/seqdb_reader/test/seqdb_perf.cpp.orig	2021-10-14 12:36:57 UTC
+++ src/objtools/blast/seqdb_reader/test/seqdb_perf.cpp
@@ -138,7 +138,8 @@ CSeqDBPerfApp::x_ScanDatabase()
     LOG_POST(Info << "Will go over " << oids2iterate.size() << " sequences");
 
 #if (defined(NCBI_COMPILER_GCC) && (NCBI_COMPILER_VERSION >= 900)) || \
-    (defined(NCBI_COMPILER_ICC) && (NCBI_COMPILER_VERSION >= 2100))
+    (defined(NCBI_COMPILER_ICC) && (NCBI_COMPILER_VERSION >= 2100)) || \
+    defined(NCBI_COMPILER_LLVM_CLANG)
     #pragma omp parallel default(none) num_threads(m_DbHandles.size()) \
                          shared(oids2iterate,kScanUncompressed) if(m_DbHandles.size() > 1)
 #else
@@ -210,7 +211,8 @@ CSeqDBPerfApp::x_InitApplicationData()
 
     if (args["multi_threaded_creation"]) {
 #if (defined(NCBI_COMPILER_GCC) && (NCBI_COMPILER_VERSION >= 900)) || \
-    (defined(NCBI_COMPILER_ICC) && (NCBI_COMPILER_VERSION >= 2100))
+    (defined(NCBI_COMPILER_ICC) && (NCBI_COMPILER_VERSION >= 2100)) ||
+    defined(NCBI_COMPILER_LLVM_CLANG)
         #pragma omp parallel default(none) shared(kDbName, kNumThreads, kSeqType) num_threads(kNumThreads)
 #else
         #pragma omp parallel default(none) shared(kDbName, kNumThreads) num_threads(kNumThreads)
