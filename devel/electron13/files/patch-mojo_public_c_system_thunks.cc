--- mojo/public/c/system/thunks.cc.orig	2021-01-07 00:36:37 UTC
+++ mojo/public/c/system/thunks.cc
@@ -20,7 +20,7 @@
 #include "mojo/public/c/system/core.h"
 #include "mojo/public/c/system/macros.h"
 
-#if defined(OS_CHROMEOS) || defined(OS_LINUX) || defined(OS_WIN)
+#if defined(OS_CHROMEOS) || defined(OS_LINUX) || defined(OS_WIN) || defined(OS_BSD)
 #include "base/environment.h"
 #include "base/files/file_path.h"
 #include "base/optional.h"
@@ -68,7 +68,7 @@ class CoreLibraryInitializer {
   ~CoreLibraryInitializer() = default;
 
   MojoResult LoadLibrary(base::FilePath library_path) {
-#if defined(OS_CHROMEOS) || defined(OS_LINUX) || defined(OS_WIN)
+#if defined(OS_CHROMEOS) || defined(OS_LINUX) || defined(OS_WIN) || defined(OS_BSD)
     if (library_ && library_->is_valid())
       return MOJO_RESULT_OK;
 
@@ -82,7 +82,7 @@ class CoreLibraryInitializer {
 
     if (library_path.empty()) {
       // Default to looking for the library in the current working directory.
-#if defined(OS_CHROMEOS) || defined(OS_LINUX)
+#if defined(OS_CHROMEOS) || defined(OS_LINUX) || defined(OS_BSD)
       const base::FilePath::CharType kDefaultLibraryPathValue[] =
           FILE_PATH_LITERAL("./libmojo_core.so");
 #elif defined(OS_WIN)
@@ -126,13 +126,13 @@ class CoreLibraryInitializer {
 
     library_ = std::move(library);
     return MOJO_RESULT_OK;
-#else   // defined(OS_CHROMEOS) || defined(OS_LINUX) || defined(OS_WIN)
+#else   // defined(OS_CHROMEOS) || defined(OS_LINUX) || defined(OS_WIN) || defined(OS_BSD)
     return MOJO_RESULT_UNIMPLEMENTED;
-#endif  // defined(OS_CHROMEOS) || defined(OS_LINUX) || defined(OS_WIN)
+#endif  // defined(OS_CHROMEOS) || defined(OS_LINUX) || defined(OS_WIN) || defined(OS_BSD)
   }
 
  private:
-#if defined(OS_CHROMEOS) || defined(OS_LINUX) || defined(OS_WIN)
+#if defined(OS_CHROMEOS) || defined(OS_LINUX) || defined(OS_WIN) || defined(OS_BSD)
   base::Optional<base::ScopedNativeLibrary> library_;
 #endif
 };
