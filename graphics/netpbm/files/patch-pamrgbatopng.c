--- converter/other/pamrgbatopng.c.orig	2006-08-19 05:12:28.000000000 +0200
+++ converter/other/pamrgbatopng.c	2012-04-24 22:20:00.000000000 +0200
@@ -1,4 +1,5 @@
 #include <png.h>
+#include <pngpriv.h>
 #include <stdio.h>
 #include <stdlib.h>
 #include <setjmp.h>
