--- src/base/init_mozc.cc.orig	2026-04-06 14:54:27 UTC
+++ src/base/init_mozc.cc
@@ -39,6 +39,7 @@
 #endif  // _WIN32
 
 #include <string>
+#include <stdlib.h>
 
 #include "absl/flags/flag.h"
 #include "absl/flags/parse.h"
@@ -113,7 +114,9 @@ void InitMozc(const char* arg0, int* argc, char*** arg
     SetUnhandledExceptionFilterForWindows();
   }
   ParseCommandLineFlags(*argc, *argv);
-  RegisterLogFileSink(GetLogFilePathFromProgramName(program_name));
+  const char *nolog = getenv("MOZC_NOLOG");
+  if (nolog == NULL)
+    RegisterLogFileSink(GetLogFilePathFromProgramName(program_name));
 }
 
 }  // namespace mozc
