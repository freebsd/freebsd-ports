--- src/db/DatabaseQueue.cxx.orig	2017-01-03 19:47:53 UTC
+++ src/db/DatabaseQueue.cxx
@@ -27,14 +27,13 @@
 
 #include <functional>
 
-static bool
+static void
 AddToQueue(Partition &partition, const LightSong &song)
 {
 	const Storage &storage = *partition.instance.storage;
 	partition.playlist.AppendSong(partition.pc,
 				      DatabaseDetachSong(storage,
 							 song));
-	return true;
 }
 
 void
