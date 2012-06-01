--- png.c.orig	2008-11-12 02:39:40.000000000 +0100
+++ png.c	2012-04-25 06:46:07.000000000 +0200
@@ -21,6 +21,7 @@
 #include <stdio.h>
 #include <stdlib.h>
 #include <png.h>
+#include <pngpriv.h>
 #include <setjmp.h>
 
 #include "config.h"
