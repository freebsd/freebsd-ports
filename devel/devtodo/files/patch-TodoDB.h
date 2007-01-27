--- src/TodoDB.h.orig	Fri Sep  3 11:35:14 2004
+++ src/TodoDB.h	Sat Jan 27 14:11:37 2007
@@ -108,7 +108,7 @@
 		void initColour();
 		void initColourPost();
 		Todo::Priority getPriority(string current = "");
-		int TodoDB::markDone(Todo &todo);
+		int markDone(Todo &todo);
 
 		void formatItem(ostream &out, int depth, Todo const &item, string const &format);
 
