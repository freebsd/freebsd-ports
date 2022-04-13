--- xtron.c.orig	1995-04-16 12:48:44 UTC
+++ xtron.c
@@ -21,6 +21,9 @@
 
 #include "xtron.h"
 
+struct Player p[2];
+struct Board b;
+
 void plr_setup(void)
 {
   int i;
