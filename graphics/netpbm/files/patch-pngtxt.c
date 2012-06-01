--- converter/other/pngtxt.c.orig	2006-08-19 05:12:28.000000000 +0200
+++ converter/other/pngtxt.c	2012-04-24 22:12:39.000000000 +0200
@@ -2,6 +2,7 @@
 #include <string.h>
 #include <stdio.h>
 #include <png.h>
+#include <pngpriv.h>
 
 #include "nstring.h"
 #include "pngtxt.h"
