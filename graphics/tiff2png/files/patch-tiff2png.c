--- tiff2png.c.orig	2002-09-13 01:00:00.000000000 +0200
+++ tiff2png.c	2012-04-27 07:10:32.000000000 +0200
@@ -87,6 +87,7 @@
 #  include "tiffcomp.h"		/* not installed by default */
 #endif
 #include "png.h"
+#include "zlib.h"
 
 #ifdef _MSC_VER   /* works for MSVC 5.0; need finer tuning? */
 #  define strcasecmp _stricmp
