--- third_party/maldoca/src/maldoca/service/common/process_doc_wrapper.cc.orig	2023-10-19 19:59:12 UTC
+++ third_party/maldoca/src/maldoca/service/common/process_doc_wrapper.cc
@@ -7,7 +7,7 @@
 #include "build/build_config.h"
 
 #include "base/files/file_util.h"
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || BUILDFLAG(IS_BSD)
 #include "base/strings/string_util.h"
 #else
 #include "base/strings/string_util_win.h"
@@ -21,7 +21,7 @@ namespace third_party_maldoca {
 
 
 bool ExtensionEqualInCaseSensitive(base::FilePath file_path, std::string extension){
-  #if defined(OS_LINUX)
+  #if defined(OS_LINUX) || BUILDFLAG(IS_BSD)
   std::string file_extension = file_path.FinalExtension();
   return base::CompareCaseInsensitiveASCII(file_extension, extension) == 0;
   #else
@@ -74,7 +74,7 @@ void AnalyzeOfficeDocument(base::File office_file,
   maldoca::DocProcessor doc_processor(processor_config);
 
   maldoca::ProcessDocumentRequest process_doc_request;
-  #if defined(OS_LINUX)
+  #if defined(OS_LINUX) || BUILDFLAG(IS_BSD)
   const std::string file_name = file_path.BaseName().value().c_str();
   process_doc_request.set_file_name(file_name);
   #endif
