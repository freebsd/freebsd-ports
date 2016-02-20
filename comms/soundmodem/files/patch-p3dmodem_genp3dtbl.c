--- p3dmodem/genp3dtbl.c.orig	2002-08-09 20:01:52 UTC
+++ p3dmodem/genp3dtbl.c
@@ -39,6 +39,8 @@
 #include <float.h>
 #include <stdio.h>
 
+unsigned int log_verblevel;
+
 /* ---------------------------------------------------------------------- */
 
 extern inline unsigned int hweight32(unsigned int w)
