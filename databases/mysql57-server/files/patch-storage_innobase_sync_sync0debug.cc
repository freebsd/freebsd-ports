--- storage/innobase/sync/sync0debug.cc.orig	2016-03-28 18:06:12 UTC
+++ storage/innobase/sync/sync0debug.cc
@@ -1702,7 +1702,7 @@ private:
 		const void*,
 		File,
 		std::less<const void*>,
-		ut_allocator<std::pair<const void*, File> > >
+		ut_allocator<std::pair<const void* const, File> > >
 		Files;
 
 	typedef OSMutex	Mutex;
