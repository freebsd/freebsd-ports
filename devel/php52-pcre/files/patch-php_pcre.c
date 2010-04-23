--- php_pcre.c.orig	2009-03-06 10:58:43.000000000 +0100
+++ php_pcre.c	2009-03-06 10:58:56.000000000 +0100
@@ -18,6 +18,10 @@
 
 /* $Id: php_pcre.c,v 1.168.2.9.2.30 2009/01/13 19:23:31 andrei Exp $ */
 
+#ifdef HAVE_CONFIG_H
+#include "config.h"
+#endif
+
 #include "php.h"
 #include "php_ini.h"
 #include "php_globals.h"
