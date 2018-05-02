--- fdbserver/VFSAsync.cpp.orig	2018-04-28 14:51:27 UTC
+++ fdbserver/VFSAsync.cpp
@@ -460,7 +460,7 @@ static int asyncDeviceCharacteristics(sq
 			//resulting in a locking error
 			auto itr = SharedMemoryInfo::table.find(filename);
 			if(itr != SharedMemoryInfo::table.end()) {
-				ASSERT(itr->second.refcount == 0);
+				ASSERT_ABORT(itr->second.refcount == 0);
 				itr->second.cleanup();
 			}
 		}
