--- efence.c.orig	Mon Jan 13 17:24:08 2003
+++ efence.c	Mon Jan 13 17:22:50 2003
@@ -271,7 +271,9 @@
 	char *	string;
 	Slot *	slot;
 
+#if 0
 	EF_Print(version);
+#endif
 
 #ifdef USE_SEMAPHORE
 	if (sem_init(&EF_sem, 0, 1) >= 0) {
