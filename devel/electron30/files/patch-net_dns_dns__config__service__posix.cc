--- net/dns/dns_config_service_posix.cc.orig	2023-02-15 13:08:44 UTC
+++ net/dns/dns_config_service_posix.cc
@@ -34,6 +34,11 @@
 #include "net/dns/dns_config_watcher_mac.h"
 #endif
 
+#if BUILDFLAG(IS_BSD)
+#include "base/command_line.h"
+#include "sandbox/policy/switches.h"
+#endif
+
 namespace net {
 
 namespace internal {
@@ -130,6 +135,12 @@ class DnsConfigServicePosix::Watcher : public DnsConfi
 
   bool Watch() override {
     CheckOnCorrectSequence();
+
+// pledge + unveil
+    base::CommandLine* command_line = base::CommandLine::ForCurrentProcess();
+    if (!command_line->HasSwitch(sandbox::policy::switches::kNoSandbox))
+      return false;
+
     bool success = true;
 #if !IS_MAS_BUILD()
     if (!config_watcher_.Watch(base::BindRepeating(&Watcher::OnConfigChanged,
