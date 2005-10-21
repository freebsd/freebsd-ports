--- tty.c.orig	Fri Mar 18 10:40:11 2005
+++ tty.c	Fri May  6 16:58:38 2005
@@ -1074,8 +1074,10 @@
 			setsid();	/* I think you do setprgp(0,0) on systems with no setsid() */
 #ifndef SETPGRP_VOID
 			setpgrp(0, 0);
+/*
 #else
 			setpgrp();
+*/
 #endif
 
 #endif
