--- src/netlist.c.orig	Mon Jul 10 11:19:14 2006
+++ src/netlist.c	Mon Jul 10 11:19:23 2006
@@ -29,6 +29,8 @@
 /* generic netlist operations
  */
 
+#include <sys/types.h>
+
 #ifdef HAVE_CONFIG_H
 #include "config.h"
 #endif
