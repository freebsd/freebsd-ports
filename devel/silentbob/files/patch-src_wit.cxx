--- src/wit.cxx.orig	2013-11-27 15:00:47 UTC
+++ src/wit.cxx
@@ -18,7 +18,7 @@ int what_is_this (char * d_op, char ch)
 
 	d_words_count = words_count (d_op);
 
-	if (words_count <= 0)
+	if (d_words_count <= 0)
 		return OT::Other;
 	
 	if (d_words_count == 1) {
