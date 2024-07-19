--- chrome/utility/services.cc.orig	2024-06-18 21:43:27 UTC
+++ chrome/utility/services.cc
@@ -38,7 +38,7 @@
 #include "services/screen_ai/screen_ai_service_impl.h"  // nogncheck
 #endif
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "services/passage_embeddings/passage_embeddings_service.h"
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(LINUX)
 
@@ -61,7 +61,7 @@
 #include "chrome/services/system_signals/mac/mac_system_signals_service.h"
 #endif  // BUILDFLAG(IS_MAC)
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "chrome/services/system_signals/linux/linux_system_signals_service.h"
 #endif  // BUILDFLAG(IS_LINUX)
 
@@ -82,7 +82,7 @@
 #include "chrome/services/file_util/file_util_service.h"  // nogncheck
 #endif
 
-#if BUILDFLAG(FULL_SAFE_BROWSING) && (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN))
+#if BUILDFLAG(FULL_SAFE_BROWSING) && (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)) || BUILDFLAG(IS_BSD)
 #include "chrome/services/file_util/document_analysis_service.h"  // nogncheck
 #endif
 
@@ -221,7 +221,7 @@ auto RunMacNotificationService(
 }
 #endif  // BUILDFLAG(IS_MAC)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 auto RunPassageEmbeddingsService(
     mojo::PendingReceiver<passage_embeddings::mojom::PassageEmbeddingsService>
         receiver) {
@@ -288,7 +288,7 @@ auto RunCupsIppParser(
 }
 #endif
 
-#if BUILDFLAG(FULL_SAFE_BROWSING) && (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN))
+#if BUILDFLAG(FULL_SAFE_BROWSING) && (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)) || BUILDFLAG(IS_BSD)
 auto RunDocumentAnalysis(
     mojo::PendingReceiver<chrome::mojom::DocumentAnalysisService> receiver) {
   return std::make_unique<DocumentAnalysisService>(std::move(receiver));
@@ -494,7 +494,7 @@ void RegisterMainThreadServices(mojo::ServiceFactory& 
   services.Add(RunWindowsIconReader);
 #endif  // BUILDFLAG(IS_WIN)
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   services.Add(RunPassageEmbeddingsService);
   services.Add(RunSystemSignalsService);
 #endif  // BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
@@ -511,7 +511,7 @@ void RegisterMainThreadServices(mojo::ServiceFactory& 
   services.Add(RunFileUtil);
 #endif
 
-#if BUILDFLAG(FULL_SAFE_BROWSING) && (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN))
+#if BUILDFLAG(FULL_SAFE_BROWSING) && (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)) || BUILDFLAG(IS_BSD)
   services.Add(RunDocumentAnalysis);
 #endif
 
