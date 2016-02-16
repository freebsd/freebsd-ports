--- src/octave/pfsclose.cpp.orig	2016-02-12 17:10:27 UTC
+++ src/octave/pfsclose.cpp
@@ -53,9 +53,9 @@ DEFUN_DLD( pfsclose, args, , helpString 
     return retval;
   }
 
-  Octave_map pfsStream = args(0).map_value();
+  octave_map pfsStream = args(0).map_value();
 
-  Octave_map::const_iterator itFH = pfsStream.seek( "FH" );
+  octave_map::const_iterator itFH = pfsStream.seek( "FH" );
   if( itFH == pfsStream.end() ||
     !pfsStream.contents( itFH )(0).is_real_scalar() )
   {
