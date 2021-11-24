--- components/discardable_memory/service/discardable_shared_memory_manager.cc.orig	2021-04-14 01:08:45 UTC
+++ components/discardable_memory/service/discardable_shared_memory_manager.cc
@@ -33,7 +33,7 @@
 #include "components/discardable_memory/common/discardable_shared_memory_heap.h"
 #include "mojo/public/cpp/bindings/self_owned_receiver.h"
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 #include "base/files/file_path.h"
 #include "base/files/file_util.h"
 #include "base/metrics/histogram_macros.h"
