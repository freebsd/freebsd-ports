--- src/density.cc.orig	Tue Jan  1 20:43:01 2002
+++ src/density.cc	Thu Jun 26 02:41:35 2003
@@ -49,7 +49,7 @@
 //**************************************
 // Constructeur
 //**************************************
-PovTexDensity::PovTexDensity( app_objs *appref, void (*asuicidal_func)(gpointer, gpointer), gpointer amother, bool is_top=true ) : MaterialItem( app_ref )
+PovTexDensity::PovTexDensity( app_objs *appref, void (*asuicidal_func)(gpointer, gpointer), gpointer amother, bool is_top ) : MaterialItem( app_ref )
 {
 num = ++count;
 char text[25];
@@ -74,7 +74,7 @@
 warp = new TvWidget_warp_rb( N_("Warp"), "WARP", NULL, app_ref );
 }
 
-void PovTexDensity::set_params( void (*asuicidal_func)(gpointer, gpointer), gpointer amother, bool is_top=true )
+void PovTexDensity::set_params( void (*asuicidal_func)(gpointer, gpointer), gpointer amother, bool is_top )
 {
 suicidal_func = asuicidal_func;
 mother = amother;
@@ -337,7 +337,7 @@
 if ( map_editor != NULL ) map_editor->flush();
 }
 
-void PovTexDensity::output_to_povray( ofstream & file, bool inmap = false )
+void PovTexDensity::output_to_povray( ofstream & file, bool inmap )
 {
 if ( !inmap ) file << "\n\t\t\tdensity {\n\t\t\t\t";
 
