--- src/shm.c.orig	2026-09-14 13:20:51 UTC
+++ src/shm.c
@@ -290,7 +290,11 @@ shm_update_strand_exit(uperf_shm_t *shm)
 shm_update_strand_exit(uperf_shm_t *shm)
 {
 #ifdef HAVE_STDATOMIC_H
+#ifdef __FreeBSD__
+	(void) __atomic_fetch_add(&shm->finished, 1, __ATOMIC_SEQ_CST);
+#else
 	(void) atomic_fetch_add(&shm->finished, 1);
+#endif
 #elif defined(HAVE_ATOMIC_H)
 	atomic_add_32(&shm->finished, 1);
 #else
