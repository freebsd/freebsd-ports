
$FreeBSD$

--- liboaf/oaf-registration.c	2001/09/04 11:05:52	1.1
+++ liboaf/oaf-registration.c	2001/09/04 11:06:15
@@ -395,6 +395,7 @@
 		if (od_iorstr)
 		  oaf_setenv ("OAF_OD_IOR", od_iorstr);
                 
+		sigprocmask (SIG_SETMASK, &omask, NULL);
 
 		close (iopipes[0]);
                 
