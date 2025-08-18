/usr/ports/security/openssl34/files/patch-crypto_threads__pthread.c

--- vendor/openssl-src-300.5.0+3.5.0/openssl/crypto/threads_pthread.c.orig	2025-05-09 22:37:37.000000000 +0200
+++ vendor/openssl-src-300.5.0+3.5.0/openssl/crypto/threads_pthread.c	2025-05-21 14:44:18.563852000 +0200
@@ -50,6 +50,10 @@ __tsan_mutex_post_lock((x), 0, 0)
 # define BROKEN_CLANG_ATOMICS
 #endif
 
+#if defined(__FreeBSD__) && (defined(__i386__) || (defined(__powerpc__) && defined(__ILP32__)))
+#define BROKEN_CLANG_ATOMICS
+#endif
+
 #if defined(OPENSSL_THREADS) && !defined(CRYPTO_TDEBUG) && !defined(OPENSSL_SYS_WINDOWS)
 
 # if defined(OPENSSL_SYS_UNIX)
