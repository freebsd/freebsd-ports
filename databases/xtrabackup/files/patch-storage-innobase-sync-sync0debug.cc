--- storage/innobase/sync/sync0debug.cc.orig	2018-03-17 00:25:16.778406000 +0300
+++ storage/innobase/sync/sync0debug.cc	2018-03-17 00:27:34.072173000 +0300
@@ -129,7 +129,7 @@
 		os_thread_id_t,
 		Latches*,
 		os_thread_id_less,
-		ut_allocator<std::pair<const std::string, latch_meta_t> > >
+		ut_allocator<std::pair<const os_thread_id_t, Latches*> > >
 		ThreadMap;
 
 	/** Constructor */
@@ -424,7 +424,7 @@
 		latch_level_t,
 		std::string,
 		latch_level_less,
-		ut_allocator<std::pair<latch_level_t, std::string> > >
+		ut_allocator<std::pair<const latch_level_t, std::string> > >
 		Levels;
 
 	/** Mutex protecting the deadlock detector data structures. */
@@ -1718,7 +1718,7 @@
 		const void*,
 		File,
 		std::less<const void*>,
-		ut_allocator<std::pair<const void*, File> > >
+		ut_allocator<std::pair<const void* const, File> > >
 		Files;
 
 	typedef OSMutex	Mutex;
