--- _imagingft.c.orig	2013-12-16 01:41:20.000000000 +0100
+++ _imagingft.c	2013-12-16 01:42:34.000000000 +0100
@@ -70,7 +70,7 @@
     const char* message;
 } ft_errors[] =
 
-#include <freetype/fterrors.h>
+#include FT_ERRORS_H
 
 /* -------------------------------------------------------------------- */
 /* font objects */
