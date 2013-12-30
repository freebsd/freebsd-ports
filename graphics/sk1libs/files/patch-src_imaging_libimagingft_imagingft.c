--- src/imaging/libimagingft/_imagingft.c.orig	2009-11-01 01:44:12.000000000 +0100
+++ src/imaging/libimagingft/_imagingft.c	2013-12-16 01:46:04.000000000 +0100
@@ -70,7 +70,7 @@
     const char* message;
 } ft_errors[] =
 
-#include <freetype/fterrors.h>
+#include FT_ERRORS_H
 
 /* -------------------------------------------------------------------- */
 /* font objects */
