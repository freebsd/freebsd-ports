--- src/mapedit.cc.orig	Tue Jan  1 20:43:01 2002
+++ src/mapedit.cc	Thu Jun 26 02:26:27 2003
@@ -28,7 +28,7 @@
 //********************************************
 // MAP ITEM
 //********************************************
-MapItem::MapItem( char *nom, float val = -1 )
+MapItem::MapItem( char *nom, float val )
 {
 name = nom;
 value = val;
