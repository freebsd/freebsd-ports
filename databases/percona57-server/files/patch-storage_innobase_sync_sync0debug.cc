--- storage/innobase/sync/sync0debug.cc.orig	2016-11-27 19:44:54 UTC
+++ storage/innobase/sync/sync0debug.cc
@@ -1717,7 +1717,7 @@ private:
 		const void*,
 		File,
 		std::less<const void*>,
-		ut_allocator<std::pair<const void*, File> > >
+		ut_allocator<std::pair<const void* const, File> > >
 		Files;
 
 	typedef OSMutex	Mutex;
