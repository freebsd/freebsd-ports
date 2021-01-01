--- content/browser/browser_main_loop.cc.orig	2019-03-16 09:15:20 UTC
+++ content/browser/browser_main_loop.cc
@@ -238,6 +238,13 @@
 #include "base/mac/foundation_util.h"
 #endif
 
+#if defined(OS_BSD)
+#include "content/browser/sandbox_host_linux.h"
+#include "services/service_manager/zygote/common/common_sandbox_support_linux.h"
+#include "content/public/common/common_sandbox_support_linux.h"
+#include "services/service_manager/sandbox/sandbox.h"
+#endif
+
 // One of the linux specific headers defines this as a macro.
 #ifdef DestroyAll
 #undef DestroyAll
@@ -587,6 +594,11 @@ int BrowserMainLoop::EarlyInitialization() {
   // by now since a thread to start the ServiceManager has been created
   // before the browser main loop starts.
   DCHECK(SandboxHostLinux::GetInstance()->IsInitialized());
+#elif defined(OS_BSD)
+  SandboxHostLinux::GetInstance()->Init();
+  base::FileHandleMappingVector fds_to_map;
+  const int sfd = SandboxHostLinux::GetInstance()->GetChildSocket();
+  fds_to_map.push_back(std::make_pair(sfd, service_manager::GetSandboxFD()));
 #endif
 
 #if defined(USE_X11)
