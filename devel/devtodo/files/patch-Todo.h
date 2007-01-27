--- src/Todo.h.orig	Fri Sep  3 11:35:13 2004
+++ src/Todo.h	Sat Jan 27 14:10:54 2007
@@ -14,6 +14,8 @@
 	01/02/01	Initial creation
 */
 
+class TodoDB;
+
 class Todo {
 	public :
 		friend class TodoDB;
