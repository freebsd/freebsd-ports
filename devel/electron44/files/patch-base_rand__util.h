--- base/rand_util.h.orig	2026-06-23 23:37:18 UTC
+++ base/rand_util.h
@@ -219,7 +219,7 @@ decltype(auto) RandomChoice(Range&& r) {
   return r[base::RandGenerator(r.size())];
 }
 
-#if BUILDFLAG(IS_POSIX)
+#if BUILDFLAG(IS_POSIX) && !BUILDFLAG(IS_BSD)
 BASE_EXPORT int GetUrandomFD();
 #endif
 
