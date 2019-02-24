--- fdbrpc/IAsyncFile.actor.cpp.orig	2019-01-09 22:28:32 UTC
+++ fdbrpc/IAsyncFile.actor.cpp
@@ -42,7 +42,7 @@ ACTOR static Future<Void> zeroRangeHelper( Reference<I
 		Void _ = wait( yield() );
 	}
 
-	aligned_free(zeros);
+	free(zeros);
 	return Void();
 }
 
