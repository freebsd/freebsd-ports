/usr/ports/security/openssl34/files/patch-crypto_threads__pthread.c
+ fix dup IMPL_fallback_atomic_exchange_n (this code was removed in
https://github.com/openssl/openssl/commit/65787e2dc219685c30539c6f60eb6b64b890bf6f)

--- vendor/openssl-src-300.4.2+3.4.1/openssl/crypto/threads_pthread.c.orig	2025-05-09 22:37:37.000000000 +0200
+++ vendor/openssl-src-300.4.2+3.4.1/openssl/crypto/threads_pthread.c	2025-05-21 14:44:18.563852000 +0200
@@ -50,6 +50,10 @@ __tsan_mutex_post_lock((x), 0, 0)
 # define BROKEN_CLANG_ATOMICS
 #endif
 
+#if defined(__FreeBSD__) && (defined(__i386__) || (defined(__powerpc__) && defined(__ILP32__)))
+#define BROKEN_CLANG_ATOMICS
+#endif
+
 #if defined(OPENSSL_THREADS) && !defined(CRYPTO_TDEBUG) && !defined(OPENSSL_SYS_WINDOWS)
 
 # if defined(OPENSSL_SYS_UNIX)
@@ -210,8 +214,7 @@ IMPL_fallback_atomic_exchange_n(prcu_cb_item)
         pthread_mutex_unlock(&atomic_sim_lock);                                       \
         return ret;                                                                   \
     }
-
-IMPL_fallback_atomic_exchange_n(uint64_t)
+IMPL_fallback_atomic_compare_exchange_n(uint64_t)
 
 #  define ATOMIC_COMPARE_EXCHANGE_N(t, p, e, d, s, f) fallback_atomic_compare_exchange_n_##t(p, e, d, s, f)
 
