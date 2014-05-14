--- gnome-initial-setup/pages/account/um-realm-manager.c.orig	2014-05-14 09:14:52.647917166 +0000
+++ gnome-initial-setup/pages/account/um-realm-manager.c	2014-05-14 09:15:20.166117911 +0000
@@ -704,9 +704,6 @@
         code = krb5_get_init_creds_opt_alloc (k5, &opts);
         g_return_val_if_fail (code == 0, code);
 
-        code = krb5_get_init_creds_opt_set_out_ccache (k5, opts, ccache);
-        g_return_val_if_fail (code == 0, code);
-
         code = krb5_get_init_creds_password (k5, &creds, principal,
                                              (char *)password,
                                              NULL, 0, 0, NULL, opts);
