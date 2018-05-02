--- fdbrpc/AsyncFileCached.actor.cpp.orig	2018-04-19 02:55:50 UTC
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
@@ -233,7 +233,7 @@ Future<Void> AsyncFileCached::quiesce() 
 AsyncFileCached::~AsyncFileCached() {
 	while ( !pages.empty() ) {
 		auto ok = pages.begin()->second->evict();
-		ASSERT( ok );
+		ASSERT_ABORT( ok );
 	}
 	openFiles.erase( filename );
 }
