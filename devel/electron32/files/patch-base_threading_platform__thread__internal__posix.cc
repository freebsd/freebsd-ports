--- base/threading/platform_thread_internal_posix.cc.orig	2024-04-15 20:33:42 UTC
+++ base/threading/platform_thread_internal_posix.cc
@@ -42,7 +42,7 @@ int GetCurrentThreadNiceValue() {
 }
 
 int GetCurrentThreadNiceValue() {
-#if BUILDFLAG(IS_NACL)
+#if BUILDFLAG(IS_NACL) || BUILDFLAG(IS_BSD)
   NOTIMPLEMENTED();
   return 0;
 #else
