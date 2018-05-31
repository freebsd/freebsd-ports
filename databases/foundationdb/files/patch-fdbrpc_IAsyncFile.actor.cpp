--- fdbrpc/IAsyncFile.actor.cpp.orig	2018-05-11 01:30:59 UTC
+++ fdbrpc/IAsyncFile.actor.cpp
@@ -42,7 +42,7 @@ ACTOR static Future<Void> zeroRangeHelper( Reference<I
 		Void _ = wait( yield() );
 	}
 
-	aligned_free(zeros);
+	free(zeros);
 	return Void();
 }
 
