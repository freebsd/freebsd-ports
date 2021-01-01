--- components/download/internal/common/base_file.cc.orig	2019-04-08 08:32:49 UTC
+++ components/download/internal/common/base_file.cc
@@ -446,7 +446,7 @@ DownloadInterruptReason BaseFile::LogInterruptReason(
   return reason;
 }
 
-#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
 
 namespace {
 
