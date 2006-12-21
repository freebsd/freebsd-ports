--- image.c.orig	Thu Dec 14 10:04:06 2006
+++ image.c	Tue Dec 19 19:00:49 2006
@@ -20,6 +20,7 @@
     $Id: image.c,v 1.33 2006/12/14 13:04:06 disconn3ct Exp $
 */
 
+#include <dlfcn.h>
 #include "quakedef.h"
 
 
