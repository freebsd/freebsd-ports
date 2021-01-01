--- src/imaging/libimagingft/_imagingft.c.orig	2009-11-01 00:44:12 UTC
+++ src/imaging/libimagingft/_imagingft.c
@@ -70,7 +70,7 @@ struct {
     const char* message;
 } ft_errors[] =
 
-#include <freetype/fterrors.h>
+#include FT_ERRORS_H
 
 /* -------------------------------------------------------------------- */
 /* font objects */
