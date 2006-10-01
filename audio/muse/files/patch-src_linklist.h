--- src/linklist.h.orig	Sun Oct  1 18:28:22 2006
+++ src/linklist.h	Sun Oct  1 18:28:52 2006
@@ -44,7 +44,7 @@
   bool movedown(int pos);
   bool moveto(int num, int pos);
   Entry *pick(int pos);  
-  Entry *Linklist::selected();
+  Entry *selected();
 
   Entry *operator[](int pos) { return pick(pos); };
 
