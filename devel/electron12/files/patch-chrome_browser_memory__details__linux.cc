--- chrome/browser/memory_details_linux.cc.orig	2021-04-14 01:08:40 UTC
+++ chrome/browser/memory_details_linux.cc
@@ -70,8 +70,10 @@ ProcessData GetProcessDataMemoryInformation(
 
     std::unique_ptr<base::ProcessMetrics> metrics(
         base::ProcessMetrics::CreateProcessMetrics(pid));
+#if !defined(OS_BSD)
     pmi.num_open_fds = metrics->GetOpenFdCount();
     pmi.open_fds_soft_limit = metrics->GetOpenFdSoftLimit();
+#endif
 
     process_data.processes.push_back(pmi);
   }
