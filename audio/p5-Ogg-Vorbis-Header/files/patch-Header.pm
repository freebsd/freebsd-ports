--- Header.pm.orig	2016-07-03 05:26:27 UTC
+++ Header.pm
@@ -7,8 +7,8 @@ use warnings;
 our $VERSION = '0.05';
 
 use Inline C => 'DATA',
-					LIBS => '-logg -lvorbis -lvorbisfile',
-					INC => '-I/inc',
+					LIBS => '-L${LOCALBASE}/lib -logg -lvorbis -lvorbisfile',
+					INC => '-I${LOCALBASE}/include',
 					AUTO_INCLUDE => '#include "inc/vcedit.h"',
 					AUTO_INCLUDE => '#include "inc/vcedit.c"',
 					VERSION => '0.05',
