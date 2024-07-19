--- chrome/services/file_util/public/mojom/safe_document_analyzer_mojom_traits.h.orig	2024-06-18 21:43:25 UTC
+++ chrome/services/file_util/public/mojom/safe_document_analyzer_mojom_traits.h
@@ -17,7 +17,7 @@
 #include "mojo/public/cpp/bindings/struct_traits.h"
 
 #if !BUILDFLAG(FULL_SAFE_BROWSING) || \
-    (!BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_WIN))
+    (!BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_WIN) && !BUILDFLAG(IS_BSD))
 #error FULL_SAFE_BROWSING should be set and either IS_LINUX or IS_WIN set.
 #endif
 
