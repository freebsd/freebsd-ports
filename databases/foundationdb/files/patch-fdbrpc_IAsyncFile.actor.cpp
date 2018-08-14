--- fdbrpc/IAsyncFile.actor.cpp.orig	2018-08-01 01:25:10 UTC
+++ fdbrpc/IAsyncFile.actor.cpp
@@ -42,7 +42,7 @@ ACTOR static Future<Void> zeroRangeHelpe
 		Void _ = wait( yield() );
 	}
 
-	aligned_free(zeros);
+	free(zeros);
 	return Void();
 }
 
