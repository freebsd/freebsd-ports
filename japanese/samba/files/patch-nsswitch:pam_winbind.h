--- nsswitch/pam_winbind.h.orig	Mon Feb 10 17:21:48 2003
+++ nsswitch/pam_winbind.h	Wed Feb 26 14:28:24 2003
@@ -31,7 +31,9 @@
 #define PAM_EXTERN extern
 #include <security/pam_appl.h> 
 
+#ifndef PAM_AUTHTOK_RECOVER_ERR
 #define PAM_AUTHTOK_RECOVER_ERR PAM_AUTHTOK_RECOVERY_ERR
+#endif
 #endif
 
 #ifdef HAVE_SECURITY_PAM_MODULES_H
