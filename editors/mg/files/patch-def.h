--- def.h.orig	2015-03-23 11:23:30 UTC
+++ def.h
@@ -13,6 +13,8 @@
 #include        "chrdef.h"
 #include        "ttydef.h"
 
+#include        <sys/types.h>
+
 
 /* necesarry to get asprintf & friends with glibc XXX doesn't work for some
  * mysterious reason! */
