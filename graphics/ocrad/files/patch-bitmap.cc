--- bitmap.cc.orig	Sun Nov 16 17:28:14 2003
+++ bitmap.cc	Sun Nov 16 17:33:30 2003
@@ -24,12 +24,11 @@
 #include "rectangle.h"
 #include "bitmap.h"
 
-
 namespace {
 
 char pbm_getrawbyte( FILE * f ) throw( Bitmap::Error )
   {
-  int ch = std::getc( f );
+  int ch = getc( f );
 
   if( ch == EOF )
     throw Bitmap::Error( "end-of-file reading pbm file.\n" );
@@ -58,7 +57,7 @@
   char ch;
   int i = 0;
 
-  do ch = pbm_getc( f ); while( std::isspace( ch ) );
+  do ch = pbm_getc( f ); while( isspace( ch ) );
   if( !std::isdigit( ch ) )
     throw Bitmap::Error( "junk in pbm file where an integer should be.\n" );
   do { i = (i * 10) + (ch - '0'); ch = pbm_getc( f ); }
@@ -71,7 +70,7 @@
   {
   char ch;
 
-  do ch = pbm_getc( f ); while( std::isspace( ch ) );
+  do ch = pbm_getc( f ); while( isspace( ch ) );
 
   if( ch == '0' ) return false;
   if( ch == '1' ) return true;
