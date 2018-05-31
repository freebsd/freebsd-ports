--- fdbrpc/AsyncFileCached.actor.cpp.orig	2018-05-30 22:33:28 UTC
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
