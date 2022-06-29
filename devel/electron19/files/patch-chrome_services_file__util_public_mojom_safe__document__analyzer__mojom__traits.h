--- chrome/services/file_util/public/mojom/safe_document_analyzer_mojom_traits.h.orig	2022-05-25 04:00:51 UTC
+++ chrome/services/file_util/public/mojom/safe_document_analyzer_mojom_traits.h
@@ -16,7 +16,7 @@
 #include "mojo/public/cpp/bindings/struct_traits.h"
 
 #if !BUILDFLAG(FULL_SAFE_BROWSING) || \
-    (!BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_WIN))
+    (!BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_WIN) && !BUILDFLAG(IS_BSD))
 #error BUILDFLAG(FULL_SAFE_BROWSING) should be set and either OS_LINUX or OS_WIN defined.
 #endif
 
