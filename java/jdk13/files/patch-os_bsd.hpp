$FreeBSD$

--- ../../hotspot1.3.1/src/os/bsd/vm/os_bsd.hpp	16 Jan 2002 18:46:39 -0000	1.2
+++ ../../hotspot1.3.1/src/os/bsd/vm/os_bsd.hpp	22 Nov 2004 17:19:42 -0000
@@ -186,7 +186,7 @@
     bool trylock() {
       verify();
       int status = pthread_mutex_trylock(_mutex);
-      if (status == EBUSY)
+      if (status == EBUSY || status = EDEADLK)
 	return false;
       assert(status == 0, "pthread_mutex_lock");
       #ifndef PRODUCT
@@ -349,7 +349,7 @@
     bool trylock() {
       verify();
       int status = pthread_mutex_trylock(_mutex);
-      if (status == EBUSY)
+      if (status == EBUSY || status = EDEADLK)
 	return false;
       assert(status == 0, "pthread_mutex_trylock");
       #ifndef PRODUCT
