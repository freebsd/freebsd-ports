--- ./modules/mod_auth_pam.c.orig	Thu Jan  2 13:25:20 2003
+++ ./modules/mod_auth_pam.c	Sat Mar 15 11:35:00 2003
@@ -57,7 +57,7 @@
 #endif /* HAVE_PAM_PAM_APPL_H */
 
 static pam_handle_t *	pamh			= NULL;
-static char *		pamconfig		= "ftp";
+static char *		pamconfig		= "ftpd";
 static char *		pam_user 		= NULL;
 static char *		pam_pass 		= NULL;
 static size_t		pam_user_len		= 0;
