--- constel.c.orig	Sun Jan 21 20:40:59 2007
+++ constel.c	Sun Jan 21 20:41:27 2007
@@ -3,6 +3,8 @@
 #include "screen.h"
 #include "circum.h"
 
+static confnd(double r, double d, double e, char **name);
+
 /* print the constellation object p is in now as a prompt message.
  */
 constellation_msg (p, np)
