--- src/objtools/blast/seqdb_reader/test/seqdb_perf.cpp.orig	2018-10-23 19:28:52 UTC
+++ src/objtools/blast/seqdb_reader/test/seqdb_perf.cpp
@@ -137,8 +137,13 @@ CSeqDBPerfApp::x_ScanDatabase()
     }
     LOG_POST(Info << "Will go over " << oids2iterate.size() << " sequences");
 
+#if defined(NCBI_COMPILER_GCC) && (NCBI_COMPILER_VERSION >= 900)
     #pragma omp parallel default(none) num_threads(m_DbHandles.size()) \
+                         shared(oids2iterate,kScanUncompressed) if(m_DbHandles.size() > 1)
+#else
+    #pragma omp parallel default(none) num_threads(m_DbHandles.size()) \
                          shared(oids2iterate) if(m_DbHandles.size() > 1)
+#endif
     {
         int thread_id = 0;
 #ifdef _OPENMP
