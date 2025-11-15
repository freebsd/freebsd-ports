--- electron/shell/services/node/node_service.cc.orig	2025-11-13 22:50:46 UTC
+++ electron/shell/services/node/node_service.cc
@@ -26,7 +26,7 @@
 #include "shell/common/v8_util.h"
 #include "shell/services/node/parent_port.h"
 
-#if !IS_MAS_BUILD()
+#if !IS_MAS_BUILD() && !BUILDFLAG(IS_BSD)
 #include "shell/common/crash_keys.h"
 #endif
 
@@ -47,7 +47,7 @@ void V8FatalErrorCallback(const char* location, const 
     GetRemote()->OnV8FatalError(location, outstream.str());
   }
 
-#if !IS_MAS_BUILD()
+#if !IS_MAS_BUILD() && !BUILDFLAG(IS_BSD)
   electron::crash_keys::SetCrashKey("electron.v8-fatal.message", message);
   electron::crash_keys::SetCrashKey("electron.v8-fatal.location", location);
 #endif
