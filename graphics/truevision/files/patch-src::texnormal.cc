--- src/texnormal.cc.orig	Tue Jan  1 20:43:01 2002
+++ src/texnormal.cc	Thu Jun 26 02:38:59 2003
@@ -44,7 +44,7 @@
 //**************************************
 // Constructeurs & Destructeurs
 //**************************************
-PovTexNormal::PovTexNormal( app_objs *appref, bool mother = true ) : MaterialItem( app_ref )
+PovTexNormal::PovTexNormal( app_objs *appref, bool mother ) : MaterialItem( app_ref )
 {
 set_name( _("Normal") );
 item_type = TV_MITEM_NORMAL;
