--- lib/rle_error.c.orig	1992-03-05 04:33:27.000000000 +0900
+++ lib/rle_error.c	2012-10-16 01:18:15.000000000 +0900
@@ -28,6 +28,7 @@
 static char rcs_id[] = "$Header: /l/spencer/src/urt/lib/RCS/rle_error.c,v 3.0.1.1 1992/03/04 19:33:27 spencer Exp $";
 #endif
 
+#include <string.h>
 #include "rle.h"
 
 /*****************************************************************
