--- php_pcre.c.orig	2007-11-14 08:11:40.000000000 +0100
+++ php_pcre.c	2007-11-14 08:11:50.000000000 +0100
@@ -18,6 +18,10 @@
 
 /* $Id: php_pcre.c,v 1.168.2.9.2.21 2007/09/20 08:10:44 tony2001 Exp $ */
 
+#ifdef HAVE_CONFIG_H
+#include "config.h"
+#endif
+
 #include "php.h"
 #include "php_ini.h"
 #include "php_globals.h"
