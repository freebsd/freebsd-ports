$FreeBSD$

--- ../../hotspot1.3.1/src/os/linux/vm/os_linux.hpp	5 Jun 2002 05:27:47 -0000	1.4
+++ ../../hotspot1.3.1/src/os/linux/vm/os_linux.hpp	22 Nov 2004 17:19:42 -0000
@@ -186,7 +186,7 @@
     bool trylock() {
       verify();
       int status = os::Solaris::mutex_trylock(_mutex);
-      if (status == EBUSY)
+      if (status == EBUSY || status == EDEADLK)
 	return false;
       assert(status == 0, "mutex_lock");
       return true;
@@ -348,7 +348,7 @@
     bool trylock() {
       verify();
       int status = os::Solaris::mutex_trylock(_mutex);
-      if (status == EBUSY)
+      if (status == EBUSY || status == EDEADLK)
 	return false;
       assert(status == 0, "mutex_trylock");
       return true;
