--- chrome/browser/memory_details_linux.cc.orig	2022-05-11 07:00:29 UTC
+++ chrome/browser/memory_details_linux.cc
@@ -13,6 +13,7 @@
 #include <set>
 
 #include "base/bind.h"
+#include "base/command_line.h"
 #include "base/files/file_util.h"
 #include "base/process/process_iterator.h"
 #include "base/process/process_metrics.h"
@@ -27,6 +28,7 @@
 #include "content/public/browser/browser_task_traits.h"
 #include "content/public/browser/browser_thread.h"
 #include "content/public/common/process_type.h"
+#include "sandbox/policy/switches.h"
 #include "ui/base/l10n/l10n_util.h"
 
 using base::ProcessEntry;
@@ -70,9 +72,18 @@ ProcessData GetProcessDataMemoryInformation(
 
     std::unique_ptr<base::ProcessMetrics> metrics(
         base::ProcessMetrics::CreateProcessMetrics(pid));
+
+    base::CommandLine* command_line = base::CommandLine::ForCurrentProcess();
+    if (!command_line->HasSwitch(sandbox::policy::switches::kNoSandbox)) {
+      pmi.num_open_fds = 0;
+      pmi.open_fds_soft_limit = 0;
+      goto out;
+    }
+
     pmi.num_open_fds = metrics->GetOpenFdCount();
     pmi.open_fds_soft_limit = metrics->GetOpenFdSoftLimit();
 
+out:
     process_data.processes.push_back(pmi);
   }
   return process_data;
