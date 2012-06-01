--- bitmap/bmpng.c.orig	2012-04-01 11:57:27.000000000 +0200
+++ bitmap/bmpng.c	2012-05-04 12:44:03.000000000 +0200
@@ -4,6 +4,7 @@
 #   include	"bmintern.h"
 #   include	"bmio.h"
 #   include	<png.h>
+#   include	<pngpriv.h>
 #   include	<appDebugon.h>
 #   include	<sioFileio.h>
 #   include	<utilEndian.h>
