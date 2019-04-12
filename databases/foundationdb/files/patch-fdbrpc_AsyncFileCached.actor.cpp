--- fdbrpc/AsyncFileCached.actor.cpp.orig	2019-04-09 00:11:05 UTC
+++ fdbrpc/AsyncFileCached.actor.cpp
@@ -31,7 +31,7 @@ EvictablePage::~EvictablePage() {
 		if (pageCache->pageSize == 4096)
 			FastAllocator<4096>::release(data);
 		else
-			aligned_free(data);
+			free(data);
 	}
 	if (index > -1) {
 		pageCache->pages[index] = pageCache->pages.back();
@@ -155,7 +155,7 @@ void AsyncFileCached::releaseZeroCopy( void* data, int
 					if (length == 4096)
 						FastAllocator<4096>::release(data);
 					else
-						aligned_free(data);
+						free(data);
 				}
 			}
 			else {
