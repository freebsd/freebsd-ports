
$FreeBSD$

--- liboaf/oaf-fork-server.c	2001/09/06 07:05:36	1.1
+++ liboaf/oaf-fork-server.c	2001/09/06 07:06:12
@@ -267,6 +267,7 @@
 		if (od_iorstr)
 		  oaf_setenv ("OAF_OD_IOR", od_iorstr);
                 
+		sigprocmask (SIG_SETMASK, &omask, NULL);
 
 		close (iopipes[0]);
                 
