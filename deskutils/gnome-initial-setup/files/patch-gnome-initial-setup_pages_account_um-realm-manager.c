$OpenBSD: patch-gnome-initial-setup_pages_account_um-realm-manager_c,v 1.5 2014/10/06 10:16:42 ajacoutot Exp $

XXX rework and push upstream

--- gnome-initial-setup/pages/account/um-realm-manager.c.orig	Tue Sep  2 05:37:52 2014
+++ gnome-initial-setup/pages/account/um-realm-manager.c	Mon Oct  6 11:55:29 2014
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
