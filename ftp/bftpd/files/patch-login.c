$FreeBSD$

--- login.c.orig	Thu Mar 28 10:10:15 2002
+++ login.c	Thu Mar 28 10:10:22 2002
@@ -323,7 +323,6 @@
 			   pam_strerror(pamh, retval));
 		return 1;
 	}
-	pam_fail_delay(pamh, 0);
 	retval = pam_authenticate(pamh, 0);
 	if (retval == PAM_SUCCESS)
 		retval = pam_acct_mgmt(pamh, 0);
