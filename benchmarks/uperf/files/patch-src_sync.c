--- src/sync.c.orig	2026-09-14 13:23:38 UTC
+++ src/sync.c
@@ -95,7 +95,11 @@ wait_barrier(barrier_t *bar)
 	assert(bar->limit > 0);
 
 #ifdef HAVE_STDATOMIC_H
+#ifdef __FreeBSD__
+	(void) __atomic_fetch_add(&bar->count, 1, __ATOMIC_SEQ_CST);
+#else
 	(void) atomic_fetch_add(&bar->count, 1);
+#endif
 #elif defined(HAVE_ATOMIC_H)
 	atomic_add_32(&bar->count, 1);
 #else
