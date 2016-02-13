--- src/octave/pfsopen.cpp.orig	2016-02-12 17:10:27 UTC
+++ src/octave/pfsopen.cpp
@@ -137,7 +137,7 @@ DEFUN_DLD( pfsopen, args, , helpString)
     }    
   }
 
-  Octave_map pfsStream;
+  octave_map pfsStream;
   pfsStream.assign( "FH", octave_value((double)((long)fh)) );
   pfsStream.assign( "MODE", writeMode ? octave_value("W") : octave_value("R") );
   pfsStream.assign( "EOF", octave_value(false) );
@@ -145,7 +145,7 @@ DEFUN_DLD( pfsopen, args, , helpString)
   if( writeMode ) {
     pfsStream.assign( "columns", octave_value(width) );
     pfsStream.assign( "rows", octave_value(height) );
-    Octave_map channels;
+    octave_map channels;
     pfsStream.assign( "channels", octave_value(channels) );    
   }
   
