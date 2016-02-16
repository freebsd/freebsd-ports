--- src/fileformat/pfsoutpfm.cpp.orig	2005-06-15 13:36:54 UTC
+++ src/fileformat/pfsoutpfm.cpp
@@ -74,7 +74,7 @@ void writePFMFileColor( FILE *fh, int wi
     }
     int written = fwrite( line, sizeof( float ), lineSize, fh );
     if( written != lineSize )
-      throw new pfs::Exception( "Unable to write data" );
+      throw pfs::Exception( "Unable to write data" );
   }
   delete[] line;  
 }
@@ -94,7 +94,7 @@ void writePFMFileGrayscale( FILE *fh, in
     }
     int written = fwrite( line, sizeof( float ), lineSize, fh );
     if( written != lineSize )
-      throw new pfs::Exception( "Unable to write data" );
+      throw pfs::Exception( "Unable to write data" );
   }
   delete[] line;  
 }
