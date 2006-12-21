--- ./modules.c.orig	Mon Mar 20 10:51:27 2006
+++ ./modules.c	Tue Aug 29 20:59:12 2006
@@ -20,6 +20,7 @@
 	$Id: modules.c,v 1.8 2006/03/20 13:51:27 vvd0 Exp $
 */
 
+#include <dlfcn.h>
 #include "quakedef.h"
 
 
