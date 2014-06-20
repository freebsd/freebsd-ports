--- src/fileformat/pfsoutpfm.cpp.orig	2005-06-15 13:36:54.000000000 +0000
+++ src/fileformat/pfsoutpfm.cpp	2014-02-20 19:04:01.546588828 +0000
@@ -74,7 +74,7 @@
     }
     int written = fwrite( line, sizeof( float ), lineSize, fh );
     if( written != lineSize )
-      throw new pfs::Exception( "Unable to write data" );
+      throw pfs::Exception( "Unable to write data" );
   }
   delete[] line;  
 }
@@ -94,7 +94,7 @@
     }
     int written = fwrite( line, sizeof( float ), lineSize, fh );
     if( written != lineSize )
-      throw new pfs::Exception( "Unable to write data" );
+      throw pfs::Exception( "Unable to write data" );
   }
   delete[] line;  
 }
