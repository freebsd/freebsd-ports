--- src/matpov.cc.orig	Tue Jan  1 20:43:01 2002
+++ src/matpov.cc	Thu Jun 26 02:35:44 2003
@@ -600,7 +600,7 @@
 }
 
 
-void PovTexture::output_to_povray( ofstream & file, bool inmap = false )
+void PovTexture::output_to_povray( ofstream & file, bool inmap )
 {
 //if ( !is_used() ) return;
 
