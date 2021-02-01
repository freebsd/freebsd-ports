--- xlib/text.c.orig	1998-03-04 18:59:19 UTC
+++ xlib/text.c
@@ -4,6 +4,7 @@
 
 #ifdef MITSHM
 #include <stdlib.h>
+#include <string.h>
 #include "inlstring.h"		/* include inline string operations */
 #include "interface.h"
 
