--- base/rand_util.h.orig	2025-04-22 20:15:27 UTC
+++ base/rand_util.h
@@ -213,7 +213,7 @@ void RandomShuffle(Itr first, Itr last) {
   std::shuffle(first, last, RandomBitGenerator());
 }
 
-#if BUILDFLAG(IS_POSIX)
+#if BUILDFLAG(IS_POSIX) && !BUILDFLAG(IS_BSD)
 BASE_EXPORT int GetUrandomFD();
 #endif
 
