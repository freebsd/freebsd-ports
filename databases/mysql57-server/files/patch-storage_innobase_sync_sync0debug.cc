--- storage/innobase/sync/sync0debug.cc.orig	2015-11-29 19:16:24 UTC
+++ storage/innobase/sync/sync0debug.cc
@@ -1704,7 +1704,7 @@ private:
 		const void*,
 		File,
 		std::less<const void*>,
-		ut_allocator<std::pair<const void*, File> > >
+		ut_allocator<std::pair<const void* const, File> > >
 		Files;
 
 	typedef OSMutex	Mutex;
