--- readline_cli.c.orig	2012-03-02 16:40:26.000000000 +0100
+++ readline_cli.c	2012-03-02 16:40:43.000000000 +0100
@@ -19,6 +19,10 @@
 
 /* $Id: readline_cli.c 321634 2012-01-01 13:15:04Z felipe $ */
 
+#ifdef HAVE_CONFIG_H
+#include "config.h"
+#endif
+
 #include "php.h"
 
 #ifndef HAVE_RL_COMPLETION_MATCHES
