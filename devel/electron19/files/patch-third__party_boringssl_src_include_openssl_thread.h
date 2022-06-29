--- third_party/boringssl/src/include/openssl/thread.h.orig	2022-05-25 04:04:26 UTC
+++ third_party/boringssl/src/include/openssl/thread.h
@@ -78,6 +78,7 @@ typedef union crypto_mutex_st {
   void *handle;
 } CRYPTO_MUTEX;
 #elif !defined(__GLIBC__)
+#include <pthread.h>
 typedef pthread_rwlock_t CRYPTO_MUTEX;
 #else
 // On glibc, |pthread_rwlock_t| is hidden under feature flags, and we can't
