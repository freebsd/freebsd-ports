--- src/base/init_mozc.cc.orig	2019-03-04 18:35:55 UTC
+++ src/base/init_mozc.cc
@@ -35,6 +35,7 @@
 #endif  // OS_WIN
 
 #include <string>
+#include <stdlib.h>
 
 #include "base/file_util.h"
 #include "base/flags.h"
@@ -94,7 +95,9 @@ void InitMozc(const char *arg0, int *argc, char ***arg
   mozc_flags::ParseCommandLineFlags(argc, argv, remove_flags);
 
   const string program_name = *argc > 0 ? (*argv)[0] : "UNKNOWN";
-  Logging::InitLogStream(GetLogFilePathFromProgramName(program_name));
+  const char *nolog = getenv("MOZC_NOLOG");
+  if (nolog == NULL)
+    Logging::InitLogStream(GetLogFilePathFromProgramName(program_name));
 
 }
 
