--- mojo/public/c/system/thunks.cc.orig	2022-05-25 04:01:04 UTC
+++ mojo/public/c/system/thunks.cc
@@ -24,7 +24,7 @@
 #include "mojo/public/c/system/message_pipe.h"
 
 #if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
 #include "base/environment.h"
 #include "base/files/file_path.h"
 #include "base/scoped_native_library.h"
@@ -73,7 +73,7 @@ class CoreLibraryInitializer {
 
   MojoResult LoadLibrary(base::FilePath library_path) {
 #if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
     if (library_ && library_->is_valid())
       return MOJO_RESULT_OK;
 
@@ -87,7 +87,7 @@ class CoreLibraryInitializer {
 
     if (library_path.empty()) {
       // Default to looking for the library in the current working directory.
-#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
       const base::FilePath::CharType kDefaultLibraryPathValue[] =
           FILE_PATH_LITERAL("./libmojo_core.so");
 #elif BUILDFLAG(IS_FUCHSIA)
@@ -143,7 +143,7 @@ class CoreLibraryInitializer {
 
  private:
 #if BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || \
-    BUILDFLAG(IS_FUCHSIA)
+    BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_BSD)
   absl::optional<base::ScopedNativeLibrary> library_;
 #endif
 };
