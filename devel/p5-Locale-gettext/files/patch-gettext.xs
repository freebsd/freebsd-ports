--- gettext.xc.orig	Tue Mar 16 15:26:42 2004
+++ gettext.xs	Tue Mar 16 15:27:04 2004
@@ -2,6 +2,7 @@
 #include "perl.h"
 #include "XSUB.h"
 #include <string.h>
+#include <libintl.h>
 
 static double
 constant(name, arg)
