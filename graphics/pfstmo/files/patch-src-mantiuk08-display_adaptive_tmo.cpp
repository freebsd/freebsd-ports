--- src/mantiuk08/display_adaptive_tmo.cpp.orig	2012-06-25 13:03:28.000000000 +0000
+++ src/mantiuk08/display_adaptive_tmo.cpp	2014-06-18 15:29:52.308951834 +0000
@@ -201,7 +201,7 @@
   
 };
 
-#define PFSEOL "\x0a"
+/*#define PFSEOL "\x0a"
 static void dumpPFS( const char *fileName, const int width, const int height, float *data, const char *channelName )
 {
   FILE *fh = fopen( fileName, "wb" );
@@ -216,7 +216,7 @@
     }
   
   fclose( fh );
-}
+}*/
 
 
 void compute_gaussian_level( const int width, const int height, const pfstmo::Array2D& in, pfstmo::Array2D& out, int level, pfstmo::Array2D& temp )
