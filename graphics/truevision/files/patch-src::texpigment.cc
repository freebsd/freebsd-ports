--- src/texpigment.cc.orig	Tue Jan  1 20:43:01 2002
+++ src/texpigment.cc	Thu Jun 26 06:28:11 2003
@@ -48,7 +48,7 @@
 //**************************************
 // Constructeur
 //**************************************
-PovTexPigment::PovTexPigment( app_objs *appref, bool mother = true ) : MaterialItem( appref )
+PovTexPigment::PovTexPigment( app_objs *appref, bool mother ) : MaterialItem( appref )
 {
 set_name( _("Pigment") );
 item_type = TV_MITEM_PIGMENT;
@@ -373,7 +373,7 @@
 }
 
 
-void PovTexPigment::output_to_povray( ofstream & file, bool in_map=false )
+void PovTexPigment::output_to_povray( ofstream & file, bool in_map )
 {
 if ( !used->value() ) return;
 if ( !in_map ) file << "\n\t\tpigment {\n\t\t\t";
