$FreeBSD$

--- ../../hotspot/src/os/bsd/vm/os_bsd.hpp.orig	Wed Oct 20 16:01:08 2004
+++ ../../hotspot/src/os/bsd/vm/os_bsd.hpp	Wed Oct 20 16:01:30 2004
@@ -353,7 +353,7 @@
     bool trylock() {
       verify();
       int status = pthread_mutex_trylock(_mutex);
-      if (status == EBUSY)
+      if (status == EBUSY || status == EDEADLK)
 	return false;
       assert(status == 0, "pthread_mutex_trylock");
       #ifndef PRODUCT
