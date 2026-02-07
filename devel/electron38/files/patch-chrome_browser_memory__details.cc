--- chrome/browser/memory_details.cc.orig	2025-08-26 20:49:50 UTC
+++ chrome/browser/memory_details.cc
@@ -334,7 +334,7 @@ void MemoryDetails::CollectChildInfoOnUIThread() {
           });
     }
 
-#if BUILDFLAG(IS_POSIX) && !BUILDFLAG(IS_MAC) && !BUILDFLAG(IS_ANDROID)
+#if BUILDFLAG(IS_POSIX) && !BUILDFLAG(IS_MAC) && !BUILDFLAG(IS_ANDROID) && !BUILDFLAG(IS_BSD)
     if (content::ZygoteHost::GetInstance()->IsZygotePid(process.pid)) {
       process.process_type = content::PROCESS_TYPE_ZYGOTE;
     }
