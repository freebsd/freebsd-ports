--- src/common/classes/locks.h.orig	Sun Aug 17 14:56:47 2003
+++ src/common/classes/locks.h	Wed Nov 12 11:12:25 2003
@@ -77,7 +77,7 @@
 
 /* Process-local spinlock. Used to manage memory heaps in threaded environment. */
 // Pthreads version of the class
-#ifndef SOLARIS
+#if !defined(SOLARIS) && !defined(DARWIN) && !defined(FREEBSD)
 class Spinlock {
 private:
 	pthread_spinlock_t spinlock;
@@ -100,6 +100,7 @@
 	}
 };
 #else
+#ifdef SOLARIS
 // Who knows why Solaris 2.6 have not THIS funny spins?
 //The next code is not comlpeted but let me compile //Konstantin
 class Spinlock {
@@ -123,6 +124,29 @@
 			system_call_failed::raise();
 	}
 };
+#else  // DARWIN and FREEBSD
+class Spinlock {
+private:
+	pthread_mutex_t mlock;
+public:
+	Spinlock() {
+		if (pthread_mutex_init(&mlock, 0))
+			system_call_failed::raise();
+	}
+	~Spinlock() {
+		if (pthread_mutex_destroy(&mlock))
+			system_call_failed::raise();
+	}
+	void enter() {
+		if (pthread_mutex_lock(&mlock))
+			system_call_failed::raise();
+	}
+	void leave() {
+		if (pthread_mutex_unlock(&mlock))
+			system_call_failed::raise();
+	}
+};
+#endif
 
 #endif
 #endif
