--- src/log_ldap.c.orig	Thu Apr 30 07:51:04 2009
+++ src/log_ldap.c	Wed May  6 22:43:33 2009
@@ -282,7 +282,8 @@
     pw_ldap_getpwnam_freefields(&pwret);    
     pwret.pw_name = (char *) name;
     pw_enabled = pw_ldap_getvalue(ld, res, LDAP_FTPSTATUS);
-    if ((pw_enabled != NULL) && (strcasecmp(pw_enabled, "TRUE") != 0)) {
+    if (pw_enabled != NULL && strcasecmp(pw_enabled, "enabled") != 0 &&
+        strcasecmp(pw_enabled, "TRUE") != 0) {
         goto error;
     }
 #ifdef QUOTAS
