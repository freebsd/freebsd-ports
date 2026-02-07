--- libsanitizer/asan/asan_thread.cpp.orig	2024-01-12 13:45:52 UTC
+++ libsanitizer/asan/asan_thread.cpp
@@ -323,7 +323,9 @@ void AsanThread::ClearShadowForThreadStackAndTLS() {
   if (tls_begin_ != tls_end_) {
     uptr tls_begin_aligned = RoundDownTo(tls_begin_, ASAN_SHADOW_GRANULARITY);
     uptr tls_end_aligned = RoundUpTo(tls_end_, ASAN_SHADOW_GRANULARITY);
-    FastPoisonShadow(tls_begin_aligned, tls_end_aligned - tls_begin_aligned, 0);
+    FastPoisonShadowPartialRightRedzone(tls_begin_aligned,
+				tls_end_ - tls_begin_aligned,
+				tls_end_aligned - tls_end_, 0);
   }
 }
 
