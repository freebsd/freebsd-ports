--- pskmodem/genpsktbl.c.orig	2013-12-14 14:02:09.000000000 -0500
+++ pskmodem/genpsktbl.c	2013-12-14 14:02:34.000000000 -0500
@@ -40,6 +40,8 @@
 #include <stdio.h>
 #include <string.h>
 
+unsigned int log_verblevel;
+
 /* ---------------------------------------------------------------------- */
 
 /* 
