--- ./src/list.cpp.orig	2002-01-17 20:56:35.000000000 +0100
+++ ./src/list.cpp	2014-02-01 23:41:06.000000000 +0100
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
