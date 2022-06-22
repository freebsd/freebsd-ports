--- net/dns/dns_config_service_posix.cc.orig	2022-05-20 04:30:53 UTC
+++ net/dns/dns_config_service_posix.cc
@@ -33,6 +33,11 @@
 #include "net/dns/dns_config_watcher_mac.h"
 #endif
 
+#if BUILDFLAG(IS_BSD)
+#include "base/command_line.h"
+#include "sandbox/policy/switches.h"
+#endif
+
 namespace net {
 
 namespace internal {
@@ -129,6 +134,12 @@ class DnsConfigServicePosix::Watcher : public DnsConfi
 
   bool Watch() override {
     CheckOnCorrectSequence();
+
+// pledge + unveil
+    base::CommandLine* command_line = base::CommandLine::ForCurrentProcess();
+    if (!command_line->HasSwitch(sandbox::policy::switches::kNoSandbox))
+      return false;
+
     bool success = true;
 #ifndef MAS_BUILD
     if (!config_watcher_.Watch(base::BindRepeating(&Watcher::OnConfigChanged,
