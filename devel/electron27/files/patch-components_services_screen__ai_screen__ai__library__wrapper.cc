--- components/services/screen_ai/screen_ai_library_wrapper.cc.orig	2023-10-19 19:58:19 UTC
+++ components/services/screen_ai/screen_ai_library_wrapper.cc
@@ -187,7 +187,7 @@ ScreenAILibraryWrapper::PerformOcr(const SkBitmap& ima
 
   // TODO(crbug.com/1443341): Remove this after fixing the crash issue on Linux
   // official.
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   free_library_allocated_char_array_(library_buffer.release());
 #endif
 
@@ -219,7 +219,7 @@ ScreenAILibraryWrapper::ExtractLayout(const SkBitmap& 
 
   // TODO(crbug.com/1443341): Remove this after fixing the crash issue on Linux
   // official.
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   free_library_allocated_char_array_(library_buffer.release());
 #endif
 
@@ -253,7 +253,7 @@ absl::optional<std::vector<int32_t>> ScreenAILibraryWr
 
   // TODO(crbug.com/1443341): Remove this after fixing the crash issue on Linux
   // official.
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   free_library_allocated_int32_array_(library_buffer.release());
 #endif
 
