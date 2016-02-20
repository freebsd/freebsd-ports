--- pammodem/genpamtbl.c.orig	2002-08-09 20:01:52 UTC
+++ pammodem/genpamtbl.c
@@ -38,6 +38,8 @@
 #include <math.h>
 #include <stdio.h>
 
+unsigned int log_verblevel;
+
 /* ---------------------------------------------------------------------- */
 
 /* 
