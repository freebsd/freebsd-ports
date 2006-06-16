$FreeBSD$

--- ../../hotspot/src/os/bsd/vm/thread_bsd.inline.hpp.orig	Thu Jun 15 17:58:02 2006
+++ ../../hotspot/src/os/bsd/vm/thread_bsd.inline.hpp	Thu Jun 15 17:59:19 2006
@@ -19,7 +19,10 @@
 
   uintptr_t raw = pd_raw_thread_id();
   int ix = pd_cache_index(raw);
-#ifdef __OpenBSD__
+// XXXBSD: disable fast case. there is a race condition where the
+// fast case returns a different thread from the slow case and has
+// been seen on both OpenBSD and FreeBSD.
+#if 1
   return ThreadLocalStorage::get_thread_via_cache_slowly(raw, ix);
 #else
   Thread *Candidate = ThreadLocalStorage::_get_thread_cache[ix];
