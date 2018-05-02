--- fdbrpc/IAsyncFile.actor.cpp.orig	2018-04-25 15:06:34 UTC
+++ fdbrpc/IAsyncFile.actor.cpp
@@ -42,7 +42,7 @@ ACTOR static Future<Void> zeroRangeHelpe
 		Void _ = wait( yield() );
 	}
 
-	aligned_free(zeros);
+	free(zeros);
 	return Void();
 }
 
