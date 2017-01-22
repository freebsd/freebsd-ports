--- libpkgconf/pkg.c.orig	2017-01-20 02:01:30 UTC
+++ libpkgconf/pkg.c
@@ -1341,7 +1341,7 @@ pkgconf_pkg_traverse(pkgconf_client_t *c
 	if (maxdepth == 0)
 		return eflags;
 
-	if ((root->flags & PKGCONF_PKG_PROPF_VIRTUAL) != PKGCONF_PKG_PROPF_VIRTUAL || (client->flags & PKGCONF_PKG_PKGF_SKIP_ROOT_VIRTUAL) != PKGCONF_PKG_PKGF_SKIP_ROOT_VIRTUAL)
+	if ((root->flags & PKGCONF_PKG_PROPF_VIRTUAL) != PKGCONF_PKG_PROPF_VIRTUAL || (client->flags & ~PKGCONF_PKG_PKGF_SKIP_ROOT_VIRTUAL) != PKGCONF_PKG_PKGF_SKIP_ROOT_VIRTUAL)
 	{
 		if (func != NULL)
 			func(client, root, data);
