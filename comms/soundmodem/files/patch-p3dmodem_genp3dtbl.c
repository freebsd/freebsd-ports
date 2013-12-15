--- p3dmodem/genp3dtbl.c.orig	2002-08-09 15:01:52.000000000 -0500
+++ p3dmodem/genp3dtbl.c	2013-12-14 17:48:45.000000000 -0500
@@ -39,6 +39,8 @@
 #include <float.h>
 #include <stdio.h>
 
+unsigned int log_verblevel;
+
 /* ---------------------------------------------------------------------- */
 
 extern inline unsigned int hweight32(unsigned int w)
