--- ./xlib/text.c.orig	1998-03-04 19:59:19.000000000 +0100
+++ ./xlib/text.c	2014-03-30 03:12:11.082033640 +0200
@@ -4,6 +4,7 @@
 
 #ifdef MITSHM
 #include <stdlib.h>
+#include <string.h>
 #include "inlstring.h"		/* include inline string operations */
 #include "interface.h"
 
