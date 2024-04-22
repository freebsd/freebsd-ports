--- chrome/browser/safe_browsing/download_protection/file_analyzer.cc.orig	2023-11-29 21:39:50 UTC
+++ chrome/browser/safe_browsing/download_protection/file_analyzer.cc
@@ -21,7 +21,7 @@
 #include "content/public/browser/browser_thread.h"
 #include "url/gurl.h"
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 #include "chrome/browser/safe_browsing/download_protection/document_analysis_service.h"
 #endif
 
@@ -85,7 +85,7 @@ void FileAnalyzer::Start(const base::FilePath& target_
   } else if (inspection_type == DownloadFileType::DMG) {
     StartExtractDmgFeatures();
 #endif
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   } else if (inspection_type == DownloadFileType::OFFICE_DOCUMENT) {
     StartExtractDocumentFeatures();
 #endif
@@ -314,7 +314,7 @@ void FileAnalyzer::OnDmgAnalysisFinished(
 }
 #endif  // BUILDFLAG(IS_MAC)
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 void FileAnalyzer::StartExtractDocumentFeatures() {
   DCHECK_CURRENTLY_ON(BrowserThread::UI);
 
