--- pammodem/genpamtbl.c.orig	2002-08-09 15:01:52.000000000 -0500
+++ pammodem/genpamtbl.c	2013-12-14 17:52:08.000000000 -0500
@@ -38,6 +38,8 @@
 #include <math.h>
 #include <stdio.h>
 
+unsigned int log_verblevel;
+
 /* ---------------------------------------------------------------------- */
 
 /* 
