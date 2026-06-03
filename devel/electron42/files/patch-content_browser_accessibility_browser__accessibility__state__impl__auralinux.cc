--- content/browser/accessibility/browser_accessibility_state_impl_auralinux.cc.orig	2026-04-28 21:06:17 UTC
+++ content/browser/accessibility/browser_accessibility_state_impl_auralinux.cc
@@ -12,6 +12,7 @@
 #include <sstream>
 #include <string>
 
+#include "base/notimplemented.h"
 #include "base/debug/crash_logging.h"
 #include "base/logging.h"
 #include "base/metrics/histogram_macros.h"
@@ -44,6 +45,10 @@ bool DiscoverOrca() {
 
 // Returns true if Orca is active.
 bool DiscoverOrca() {
+#if BUILDFLAG(IS_BSD)
+  NOTIMPLEMENTED();
+  return false;
+#else
   // NOTE: this method is run from another thread to reduce jank, since
   // there's no guarantee these system calls will return quickly.
   std::unique_ptr<DIR, decltype(&CloseDir)> proc_dir(opendir("/proc"),
@@ -81,6 +86,7 @@ bool DiscoverOrca() {
   }
 
   return is_orca_active;
+#endif
 }
 
 }  // namespace
