--- src/objtools/blast/seqdb_reader/test/seqdb_perf.cpp.orig	2019-07-10 10:11:51.713901000 -0500
+++ src/objtools/blast/seqdb_reader/test/seqdb_perf.cpp	2019-07-10 10:15:40.994964000 -0500
@@ -137,8 +137,10 @@ CSeqDBPerfApp::x_ScanDatabase()
     }
     LOG_POST(Info << "Will go over " << oids2iterate.size() << " sequences");
 
+    // kScanUncompressed is read only and initialized before threading
+    // so shared should be fine here
     #pragma omp parallel default(none) num_threads(m_DbHandles.size()) \
-                         shared(oids2iterate) if(m_DbHandles.size() > 1)
+                         shared(oids2iterate,kScanUncompressed) if(m_DbHandles.size() > 1)
     {
         int thread_id = 0;
 #ifdef _OPENMP
