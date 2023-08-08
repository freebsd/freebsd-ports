XXX rework and push upstream

--- gnome-initial-setup/pages/account/um-realm-manager.c.orig	2022-12-02 15:11:34 UTC
+++ gnome-initial-setup/pages/account/um-realm-manager.c
@@ -23,7 +23,7 @@
 
 #include "um-realm-manager.h"
 
-#include <krb5/krb5.h>
+#include <krb5.h>
 
 #include <glib.h>
 #include <glib/gi18n.h>
@@ -704,9 +704,6 @@ login_perform_kinit (krb5_context k5,
         }
 
         code = krb5_get_init_creds_opt_alloc (k5, &opts);
-        g_return_val_if_fail (code == 0, code);
-
-        code = krb5_get_init_creds_opt_set_out_ccache (k5, opts, ccache);
         g_return_val_if_fail (code == 0, code);
 
         code = krb5_get_init_creds_password (k5, &creds, principal,
