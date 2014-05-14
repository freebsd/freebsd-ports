--- gnome-initial-setup/pages/password/um-realm-manager.c.orig	2014-05-14 09:31:21.758847992 +0000
+++ gnome-initial-setup/pages/password/um-realm-manager.c	2014-05-14 09:31:31.283847033 +0000
@@ -745,9 +745,6 @@
         code = krb5_get_init_creds_opt_alloc (k5, &opts);
         g_return_val_if_fail (code == 0, code);
 
-        code = krb5_get_init_creds_opt_set_out_ccache (k5, opts, ccache);
-        g_return_val_if_fail (code == 0, code);
-
         code = krb5_get_init_creds_password (k5, &creds, principal,
                                              (char *)password,
                                              NULL, 0, 0, NULL, opts);
