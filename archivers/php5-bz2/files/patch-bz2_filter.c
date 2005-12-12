--- bz2_filter.c.orig	Mon Dec 12 22:40:14 2005
+++ bz2_filter.c	Mon Dec 12 22:40:29 2005
@@ -18,6 +18,10 @@
 
 /* $Id: bz2_filter.c,v 1.3 2005/08/03 14:06:39 sniper Exp $ */
 
+#ifdef HAVE_CONFIG_H
+#include "config.h"
+#endif
+
 #include "php.h"
 #include "php_bz2.h"
 
