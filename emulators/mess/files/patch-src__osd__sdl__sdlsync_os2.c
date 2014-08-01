--- src/osd/sdl/sdlsync_os2.c.orig
+++ src/osd/sdl/sdlsync_os2.c
@@ -91,7 +91,7 @@
 {
 	INT32 myslot = (atomic_increment32(&lock->nextindex) - 1) & (WORK_MAX_THREADS - 1);
 
-#if defined(__i386__) || defined(__x86_64__)
+#if defined(__i386__) || defined(__amd64__) || defined(__x86_64__)
 	register INT32 tmp;
 	__asm__ __volatile__ (
 		"1: clr    %[tmp]             ;"
@@ -146,7 +146,7 @@
 
 void osd_scalable_lock_release(osd_scalable_lock *lock, INT32 myslot)
 {
-#if defined(__i386__) || defined(__x86_64__)
+#if defined(__i386__) || defined(__amd64__) || defined(__x86_64__)
 	register INT32 tmp = TRUE;
 	__asm__ __volatile__ (
 		" xchg   %[haslock], %[tmp] ;"
@@ -219,7 +219,7 @@
 		do {
 			register INT32 spin = 10000; // Convenient spin count
 			register pthread_t tmp;
-#if defined(__i386__) || defined(__x86_64__)
+#if defined(__i386__) || defined(__amd64__) || defined(__x86_64__)
 			__asm__ __volatile__ (
 				"1: pause                    ;"
 				"   mov    %[holder], %[tmp] ;"
