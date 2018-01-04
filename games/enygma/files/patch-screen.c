--- screen.c.orig	2004-02-28 10:01:16 UTC
+++ screen.c
@@ -13,6 +13,7 @@
  */
 
 #include <stdio.h>
+#include <string.h>
 #ifdef CURSES_HDR
 #  include CURSES_HDR
 #else
