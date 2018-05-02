--- fdbrpc/AsyncFileCached.actor.h.orig	2018-04-28 14:44:18 UTC
+++ fdbrpc/AsyncFileCached.actor.h
@@ -450,7 +450,7 @@ struct AFCPage : public EvictablePage, p
 
 	virtual ~AFCPage() {
 		clearDirty();
-		ASSERT( flushableIndex == -1 );
+		ASSERT_ABORT( flushableIndex == -1 );
 	}
 
 	void setDirty() {
