--- core/metacling/src/TCling.cxx.orig	2023-03-22 17:40:48 UTC
+++ core/metacling/src/TCling.cxx
@@ -1249,6 +1249,8 @@ static void RegisterCxxModules(cling::Interpreter &cli
          true
 #elif defined(R__MACOSX)
          true
+#elif defined(R__FBSD)
+         true
 #else // Windows
          false
 #endif
@@ -3371,6 +3373,8 @@ void TCling::UpdateListOfLoadedSharedLibraries()
    dl_iterate_phdr(callback_for_dl_iterate_phdr, &newLibs);
    for (auto &&lib: newLibs)
       RegisterLoadedSharedLibrary(lib.c_str());
+#elif defined(R__FBSD)
+   // do nothing
 #else
    Error("TCling::UpdateListOfLoadedSharedLibraries",
          "Platform not supported!");
