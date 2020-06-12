--- src/platform/qt/CoreManager.cpp.orig	2020-06-07 01:07:14 UTC
+++ src/platform/qt/CoreManager.cpp
@@ -65,7 +65,7 @@ CoreController* CoreManager::loadGame(const QString& p
 		if (vfOriginal && (size = vfOriginal->size(vfOriginal)) > 0) {
 			void* mem = vfOriginal->map(vfOriginal, size, MAP_READ);
 			vf = VFileMemChunk(mem, size);
-			vfOriginal->unmap(vfOriginal, mem, (size_t) read);
+			vfOriginal->unmap(vfOriginal, mem, size);
 			vfOriginal->close(vfOriginal);
 		}
 	}
