--- Header.pm.orig	Tue Oct 18 17:10:12 2005
+++ Header.pm	Tue Oct 18 17:08:08 2005
@@ -7,8 +7,8 @@
 our $VERSION = '0.03';
 
 use Inline C => 'DATA',
-					LIBS => '-logg -lvorbis -lvorbisfile',
-					INC => '-I/inc',
+					LIBS => '-L${LOCALBASE}/lib -logg -lvorbis -lvorbisfile',
+					INC => '-I/inc -I${LOCALBASE}/include',
 					AUTO_INCLUDE => '#include "inc/vcedit.h"',
 					AUTO_INCLUDE => '#include "inc/vcedit.c"',
 					VERSION => '0.03',
