--- chrome/browser/memory_details.cc.orig	2026-04-28 21:06:17 UTC
+++ chrome/browser/memory_details.cc
@@ -333,7 +333,7 @@ void MemoryDetails::CollectChildInfoOnUIThread() {
           });
     }
 
-#if BUILDFLAG(IS_POSIX) && !BUILDFLAG(IS_MAC) && !BUILDFLAG(IS_ANDROID)
+#if BUILDFLAG(IS_POSIX) && !BUILDFLAG(IS_MAC) && !BUILDFLAG(IS_ANDROID) && !BUILDFLAG(IS_BSD)
     if (content::ZygoteHost::GetInstance()->IsZygotePid(process.pid)) {
       process.process_type = content::PROCESS_TYPE_ZYGOTE;
     }
