--- pskmodem/genpsktbl.c.orig	2002-08-09 20:01:52 UTC
+++ pskmodem/genpsktbl.c
@@ -40,6 +40,8 @@
 #include <stdio.h>
 #include <string.h>
 
+unsigned int log_verblevel;
+
 /* ---------------------------------------------------------------------- */
 
 /* 
