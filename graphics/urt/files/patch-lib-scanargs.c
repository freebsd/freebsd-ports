--- lib/scanargs.c.orig	Tue Oct 28 07:54:53 2003
+++ lib/scanargs.c	Tue Oct 28 07:55:14 2003
@@ -43,6 +43,7 @@
 #include "rle_config.h"
 #include <stdio.h>
 #include <ctype.h>
+#define USE_STDARG
 #ifndef USE_STDARG
 #include <varargs.h>
 #else
