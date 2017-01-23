--- libpkgconf/pkg.c.orig	2017-01-20 02:01:30 UTC
+++ libpkgconf/pkg.c
@@ -1336,6 +1336,7 @@ pkgconf_pkg_traverse(pkgconf_client_t *c
 	void *data,
 	int maxdepth)
 {
+	unsigned int saved_flags = client->flags;
 	unsigned int eflags = PKGCONF_PKG_ERRF_OK;
 
 	if (maxdepth == 0)
@@ -1346,6 +1347,7 @@ pkgconf_pkg_traverse(pkgconf_client_t *c
 		if (func != NULL)
 			func(client, root, data);
 	}
+	client->flags &= ~PKGCONF_PKG_PKGF_SKIP_ROOT_VIRTUAL;
 
 	if (!(client->flags & PKGCONF_PKG_PKGF_SKIP_CONFLICTS))
 	{
@@ -1368,6 +1370,7 @@ pkgconf_pkg_traverse(pkgconf_client_t *c
 		if (eflags != PKGCONF_PKG_ERRF_OK)
 			return eflags;
 	}
+	client->flags = saved_flags;
 
 	return eflags;
 }
