--- src/list.cpp.orig	Sat Jan  1 14:45:36 2005
+++ src/list.cpp	Sat Jan  1 14:47:10 2005
@@ -125,7 +125,7 @@
   return (insert(indexOf(i), obj));
 }
 
-List::Result List::remove(Index * index, bool del=false){
+List::Result List::remove(Index * index, bool del){
   if (isEmpty()) return EmptyList;
   if (!index) return NullIndex;
 
@@ -155,7 +155,7 @@
   return Removed;
 }
 
-void List::empty(bool del=true){
+void List::empty(bool del){
   while (!isEmpty())
     remove(getFirst(), del);
 }
