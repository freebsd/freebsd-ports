--- fdbrpc/IAsyncFile.actor.cpp.orig	2019-04-09 00:11:05 UTC
+++ fdbrpc/IAsyncFile.actor.cpp
@@ -43,7 +43,7 @@ ACTOR static Future<Void> zeroRangeHelper( Reference<I
 		wait( yield() );
 	}
 
-	aligned_free(zeros);
+	free(zeros);
 	return Void();
 }
 
