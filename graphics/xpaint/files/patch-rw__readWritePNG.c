--- rw/readWritePNG.c.orig	2010-05-14 06:24:49.000000000 +0900
+++ rw/readWritePNG.c	2010-06-24 04:56:04.000000000 +0900
@@ -10,15 +10,14 @@
 #include <stdlib.h>
 #include <png.h>
 
-typedef char *String;
-#include <messages.h>
-#include <image.h>
-#include "rwTable.h"
-
 #include <X11/Xlib.h>
 #include <X11/Intrinsic.h>
 #include "xpaint.h"
 
+#include <messages.h>
+#include <image.h>
+#include "rwTable.h"
+
 #ifndef TRUE
 #  define TRUE 1
 #  define FALSE 0
