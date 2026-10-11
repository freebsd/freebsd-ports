Register the profiler's .sym table under the name dladdr() reports for
the executable, which on FreeBSD is the resolved path, not argv[0], so
native frames in crash backtraces are symbolized (series 0021).
FreeBSD-specific, not submitted upstream yet.
--- runtime/bin/exe_utils.cc.orig	2026-09-29 08:00:52 UTC
+++ runtime/bin/exe_utils.cc
@@ -4,6 +4,10 @@
 
 #include "bin/exe_utils.h"
 
+#if defined(__FreeBSD__)
+#include <dlfcn.h>
+#endif
+
 #include "bin/directory.h"
 #include "bin/file.h"
 #include "bin/platform.h"
@@ -141,7 +145,19 @@ void EXEUtils::LoadDartProfilerSymbols(const char* arg
 
   int64_t size = file->Length();
   MappedMemory* mapping = file->Map(File::kReadOnly, 0, size);
-  Dart_AddSymbols(argv0, mapping->address(), size);
+  const char* dso_name = argv0;
+#if defined(__FreeBSD__)
+  // The symbols are looked up by the name dladdr() reports for the
+  // executable. That is argv[0] with glibc, but FreeBSD reports the resolved
+  // path, so register them under that name.
+  Dl_info info;
+  if (dladdr(reinterpret_cast<void*>(&EXEUtils::LoadDartProfilerSymbols),
+             &info) != 0 &&
+      info.dli_fname != nullptr) {
+    dso_name = info.dli_fname;
+  }
+#endif
+  Dart_AddSymbols(dso_name, mapping->address(), size);
   mapping->Leak();  // Let us delete the object but keep the mapping.
   delete mapping;
   file->Release();
