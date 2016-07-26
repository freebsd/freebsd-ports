--- src/linklist.h.orig	2004-02-13 16:58:16 UTC
+++ src/linklist.h
@@ -44,7 +44,7 @@ class Linklist {
   bool movedown(int pos);
   bool moveto(int num, int pos);
   Entry *pick(int pos);  
-  Entry *Linklist::selected();
+  Entry *selected();
 
   Entry *operator[](int pos) { return pick(pos); };
 
