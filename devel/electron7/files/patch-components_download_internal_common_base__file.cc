--- components/download/internal/common/base_file.cc.orig	2019-12-12 12:39:30 UTC
+++ components/download/internal/common/base_file.cc
@@ -593,7 +593,7 @@ GURL GetEffectiveAuthorityURL(const GURL& source_url,
 
 }  // namespace
 
-#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
 
 DownloadInterruptReason BaseFile::AnnotateWithSourceInformationSync(
     const std::string& client_guid,
@@ -611,7 +611,7 @@ DownloadInterruptReason BaseFile::AnnotateWithSourceIn
 
   return QuarantineFileResultToReason(result);
 }
-#else  // !OS_WIN && !OS_MACOSX && !OS_LINUX
+#else  // !OS_WIN && !OS_MACOSX && !OS_LINUX && !OS_BSD
 DownloadInterruptReason BaseFile::AnnotateWithSourceInformationSync(
     const std::string& client_guid,
     const GURL& source_url,
