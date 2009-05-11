--- src/gui/cgui.c.orig	2008-07-31 10:56:06.000000000 -0700
+++ src/gui/cgui.c	2008-12-08 14:04:59.000000000 -0800
@@ -32,6 +32,10 @@
 # define ICONV_CONST
 #endif
 
+#ifndef ICONV_CONST
+#define ICONV_CONST const
+#endif
+
 
 #include "cgui_p.h"
 #include "i18n_l.h"
