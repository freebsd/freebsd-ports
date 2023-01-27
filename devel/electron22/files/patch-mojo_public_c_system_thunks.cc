--- mojo/public/c/system/thunks.cc.orig	2022-11-30 08:12:58 UTC
+++ mojo/public/c/system/thunks.cc
@@ -23,7 +23,7 @@
 #include "mojo/public/c/system/message_pipe.h"
 
 #if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
 #include "base/environment.h"
 #include "base/files/file_path.h"
 #include "base/scoped_native_library.h"
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
   absl::optional<base::ScopedNativeLibrary> library_;
 #endif
 };
