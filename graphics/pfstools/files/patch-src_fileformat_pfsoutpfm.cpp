--- src/fileformat/pfsoutpfm.cpp.orig	2018-01-19 06:59:44 UTC
+++ src/fileformat/pfsoutpfm.cpp
@@ -85,7 +85,7 @@ void writePFMFileColor( FILE *fh, int wi
     }
     int written = fwrite( line, sizeof( float ), lineSize, fh );
     if( written != lineSize )
-      throw new pfs::Exception( "Unable to write data" );
+      throw pfs::Exception( "Unable to write data" );
   }
   delete[] line;  
 }
@@ -109,7 +109,7 @@ void writePFMFileGrayscale( FILE *fh, in
     }
     int written = fwrite( line, sizeof( float ), lineSize, fh );
     if( written != lineSize )
-      throw new pfs::Exception( "Unable to write data" );
+      throw pfs::Exception( "Unable to write data" );
   }
   delete[] line;  
 }
