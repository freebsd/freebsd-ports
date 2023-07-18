--- groups/bal/balb/balb_performancemonitor.cpp.orig	2023-08-03 22:06:53 UTC
+++ groups/bal/balb/balb_performancemonitor.cpp
@@ -670,7 +670,7 @@ int PerformanceMonitor::Collector<bsls::Platform::OsFr
 
     bsl::ifstream ifs(filename.str().c_str());
     if (!ifs) {
-        BSLS_LOG_DEBUG("Failed to open '%s'", filename.str());
+        BSLS_LOG_DEBUG("Failed to open '%s'", filename.str().c_str());
         return -1;
     }
 
