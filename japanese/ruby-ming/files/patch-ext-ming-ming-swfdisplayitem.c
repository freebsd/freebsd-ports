--- ext/ming/ming/swfdisplayitem.c.orig	2003-09-28 14:40:42.000000000 +0900
+++ ext/ming/ming/swfdisplayitem.c	2014-01-29 17:11:21.000000000 +0900
@@ -190,7 +190,7 @@
   struct RSWFDisplayItem *i;
 
   Data_Get_Struct(self, struct RSWFDisplayItem, i);
-  SWFDisplayItem_setName(i->this, STR2CSTR(n));
+  SWFDisplayItem_setName(i->this, StringValuePtr(n));
 
   return self;
 }
