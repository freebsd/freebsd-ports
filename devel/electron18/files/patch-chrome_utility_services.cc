--- chrome/utility/services.cc.orig	2022-05-19 05:17:39 UTC
+++ chrome/utility/services.cc
@@ -63,7 +63,7 @@
 #include "chrome/services/file_util/file_util_service.h"  // nogncheck
 #endif
 
-#if BUILDFLAG(FULL_SAFE_BROWSING) && (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN))
+#if BUILDFLAG(FULL_SAFE_BROWSING) && (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD))
 #include "chrome/services/file_util/document_analysis_service.h"  // nogncheck
 #endif
 
@@ -216,7 +216,7 @@ auto RunCupsIppParser(
 }
 #endif
 
-#if BUILDFLAG(FULL_SAFE_BROWSING) && (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN))
+#if BUILDFLAG(FULL_SAFE_BROWSING) && (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD))
 auto RunDocumentAnalysis(
     mojo::PendingReceiver<chrome::mojom::DocumentAnalysisService> receiver) {
   return std::make_unique<DocumentAnalysisService>(std::move(receiver));
@@ -382,7 +382,7 @@ void RegisterMainThreadServices(mojo::ServiceFactory& 
   services.Add(RunFileUtil);
 #endif
 
-#if BUILDFLAG(FULL_SAFE_BROWSING) && (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN))
+#if BUILDFLAG(FULL_SAFE_BROWSING) && (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD))
   services.Add(RunDocumentAnalysis);
 #endif
 
