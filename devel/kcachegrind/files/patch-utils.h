--- kcachegrind/utils.h.orig	Wed Aug 25 09:14:10 2004
+++ kcachegrind/utils.h	Wed Aug 25 09:15:21 2004
@@ -151,7 +151,7 @@
     struct AppendListChunk {
 	int size;
 	struct AppendListChunk* next;
-	type* data[0];
+	// type* data[0];
     };
 
     struct AppendListChunk *_next, *_current, *_last;
