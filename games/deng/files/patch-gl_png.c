--- doomsday/engine/portable/src/gl_png.c.orig	2010-04-07 22:52:50.000000000 +0200
+++ doomsday/engine/portable/src/gl_png.c	2012-04-29 06:31:36.000000000 +0200
@@ -32,6 +32,7 @@
 // HEADER FILES ------------------------------------------------------------
 
 #include <png.h>
+#include <pngpriv.h>
 #include <setjmp.h>
 
 #include "de_base.h"
