--- electron/shell/services/node/node_service.cc.orig	2024-10-22 02:29:46 UTC
+++ electron/shell/services/node/node_service.cc
@@ -21,7 +21,7 @@
 #include "shell/common/node_includes.h"
 #include "shell/services/node/parent_port.h"
 
-#if !IS_MAS_BUILD()
+#if !IS_MAS_BUILD() && !BUILDFLAG(IS_BSD)
 #include "shell/common/crash_keys.h"
 #endif
 
@@ -38,7 +38,7 @@ void V8FatalErrorCallback(const char* location, const 
     g_client_remote->OnV8FatalError(location, outstream.str());
   }
 
-#if !IS_MAS_BUILD()
+#if !IS_MAS_BUILD() && !BUILDFLAG(IS_BSD)
   electron::crash_keys::SetCrashKey("electron.v8-fatal.message", message);
   electron::crash_keys::SetCrashKey("electron.v8-fatal.location", location);
 #endif
