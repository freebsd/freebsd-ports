--- screen.c.orig	Sun Sep 14 23:24:17 2008
+++ screen.c	Sun Sep 14 22:01:21 2008
@@ -13,6 +13,7 @@
  */
 
 #include <stdio.h>
+#include <string.h>
 #ifdef CURSES_HDR
 #  include CURSES_HDR
 #else
