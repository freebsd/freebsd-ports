--- xfsm_util.c.orig	Thu Feb 18 04:35:38 1999
+++ xfsm_util.c	Wed Mar 15 03:08:33 2000
@@ -152,7 +152,7 @@
 		/* *** FreeBSD has fsize which is the physical block size *** */
 		/* *** and bsize which is the optimal transfer block size *** */
 		/* *** and which depends on the filesystem parameter.     *** */
-		calc_bsize=stats[i].f_fsize;
+		calc_bsize=stats[i].f_bsize;
 #endif /* FreeBSD */
 
 	/* *** take the longer of the two 'problematic' strings *** */
