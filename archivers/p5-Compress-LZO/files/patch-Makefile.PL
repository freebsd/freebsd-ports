--- Makefile.PL.orig	1998-08-23 10:14:41 UTC
+++ Makefile.PL
@@ -14,6 +14,8 @@ use Config;
 # installed.
 
 #$LZO_LIB     = '-L/usr/local/lib';
+$LZO_INCLUDE = '-I%%LOCALBASE%%/include';
+$LZO_LIB     = '-L%%LOCALBASE%%/lib';
 
 
 # It shouldn't be necessary to change anything from here on.
@@ -21,7 +23,7 @@ use Config;
 WriteMakefile(
                 NAME   	 	=> 'Compress::LZO',
 		VERSION_FROM  	=> 'LZO.pm',
-		LIBS	 	=> [ "$LZO_LIB -llzo" ],
+		LIBS	 	=> [ "$LZO_LIB -llzo2" ],
 	      	INC      	=> "$LZO_INCLUDE",
 		'dist'	 	=> {COMPRESS=>'gzip', SUFFIX=>'gz'},
 	     );
