--- tty.c.orig	Fri Dec  7 19:19:54 2001
+++ tty.c	Fri Dec  7 19:20:13 2001
@@ -1006,8 +1006,10 @@
 
 #ifndef SETPGRP_VOID
 			setpgrp(0, 0);
+/*
 #else
 			setpgrp();
+*/
 #endif
 
 			for (x = 0; x != 32; ++x)
