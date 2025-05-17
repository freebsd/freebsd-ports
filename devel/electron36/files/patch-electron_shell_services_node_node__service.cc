--- electron/shell/services/node/node_service.cc.orig	2025-01-29 20:10:57 UTC
+++ electron/shell/services/node/node_service.cc
@@ -22,7 +22,7 @@
 #include "shell/common/node_includes.h"
 #include "shell/services/node/parent_port.h"
 
-#if !IS_MAS_BUILD()
+#if !IS_MAS_BUILD() && !BUILDFLAG(IS_BSD)
 #include "shell/common/crash_keys.h"
 #endif
 
@@ -39,7 +39,7 @@ void V8FatalErrorCallback(const char* location, const 
     g_client_remote->OnV8FatalError(location, outstream.str());
   }
 
-#if !IS_MAS_BUILD()
+#if !IS_MAS_BUILD() && !BUILDFLAG(IS_BSD)
   electron::crash_keys::SetCrashKey("electron.v8-fatal.message", message);
   electron::crash_keys::SetCrashKey("electron.v8-fatal.location", location);
 #endif
