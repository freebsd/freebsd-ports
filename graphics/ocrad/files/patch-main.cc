--- main.cc.orig	Fri Oct 14 16:46:22 2005
+++ main.cc	Fri Oct 14 16:46:30 2005
@@ -198,7 +198,7 @@
 void Ocrad::internal_error( const char * msg ) throw()
   {
   char buf[80];
-  std::snprintf( buf, sizeof( buf ), "internal error: %s.\n", msg );
+  snprintf( buf, sizeof( buf ), "internal error: %s.\n", msg );
   show_error( buf );
   exit( 3 );
   }
