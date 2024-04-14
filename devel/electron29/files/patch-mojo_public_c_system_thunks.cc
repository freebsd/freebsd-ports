--- mojo/public/c/system/thunks.cc.orig	2024-02-21 00:20:49 UTC
+++ mojo/public/c/system/thunks.cc
@@ -24,7 +24,7 @@
 #include "mojo/public/c/system/message_pipe.h"
 
 #if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
 #include <optional>
 #include "base/environment.h"
 #include "base/files/file_path.h"
@@ -72,7 +72,7 @@ class CoreLibraryInitializer {
 
   MojoResult LoadLibrary(base::FilePath library_path) {
 #if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
     if (library_ && library_->is_valid())
       return MOJO_RESULT_OK;
 
@@ -86,7 +86,7 @@ class CoreLibraryInitializer {
 
     if (library_path.empty()) {
       // Default to looking for the library in the current working directory.
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
       const base::FilePath::CharType kDefaultLibraryPathValue[] =
           FILE_PATH_LITERAL("./libmojo_core.so");
 #elif BUILDFLAG(IS_FUCHSIA)
@@ -142,7 +142,7 @@ class CoreLibraryInitializer {
 
  private:
 #if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
   std::optional<base::ScopedNativeLibrary> library_;
 #endif
 };
