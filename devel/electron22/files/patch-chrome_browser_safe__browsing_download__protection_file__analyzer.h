--- chrome/browser/safe_browsing/download_protection/file_analyzer.h.orig	2022-11-30 08:12:58 UTC
+++ chrome/browser/safe_browsing/download_protection/file_analyzer.h
@@ -18,7 +18,7 @@
 #include "components/safe_browsing/core/common/proto/csd.pb.h"
 #include "third_party/protobuf/src/google/protobuf/repeated_field.h"
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
 #include "chrome/services/file_util/public/cpp/sandboxed_document_analyzer.h"
 #endif
 
@@ -106,7 +106,7 @@ class FileAnalyzer {
       const safe_browsing::ArchiveAnalyzerResults& archive_results);
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   void StartExtractDocumentFeatures();
   void OnDocumentAnalysisFinished(
       const DocumentAnalyzerResults& document_results);
@@ -133,7 +133,7 @@ class FileAnalyzer {
   scoped_refptr<SandboxedDMGAnalyzer> dmg_analyzer_;
 #endif
 
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD)
   scoped_refptr<SandboxedDocumentAnalyzer> document_analyzer_;
   base::TimeTicks document_analysis_start_time_;
 #endif
