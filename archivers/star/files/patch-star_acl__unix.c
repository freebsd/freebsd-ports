--- star/acl_unix.c.orig	2014-03-31 17:44:46 UTC
+++ star/acl_unix.c
@@ -1,8 +1,8 @@
-/* @(#)acl_unix.c	1.49 14/03/31 Copyright 2001-2014 J. Schilling */
+/* @(#)acl_unix.c	1.51 16/09/03 Copyright 2001-2014 J. Schilling */
 #include <schily/mconfig.h>
 #ifndef lint
 static	UConst char sccsid[] =
-	"@(#)acl_unix.c	1.49 14/03/31 Copyright 2001-2014 J. Schilling";
+	"@(#)acl_unix.c	1.51 16/09/03 Copyright 2001-2014 J. Schilling";
 #endif
 /*
  *	ACL get and set routines for unix like operating systems.
@@ -11,7 +11,7 @@ static	UConst char sccsid[] =
  *
  *	There are currently two basic flavors of ACLs:
  *
- *	Flavor 1: UFS/POSIX draft
+ *	Flavor 1: UFS/POSIX.1e draft (withrawn in 1997)
  *
  *	The Solaric UFS ACLs that have been developed between 1990 and 1994.
  *	These ACLs have been made available as extensions to NFSv2 and NFSv3.
@@ -27,7 +27,7 @@ static	UConst char sccsid[] =
  *	As True64 does not like ACL "mask" entries and this version of the
  * 	ACL code does not generate "mask" entries on True64, ACL support for
  *	True64 is currently broken. You cannot read back archives created
- *	on true64.
+ *	on True64.
  *
  *	Flavor 2: NFSv4
  *
@@ -196,6 +196,9 @@ EXPORT void
 opt_acl()
 {
 	printf(" acl-POSIX.1e-draft");
+#ifdef	HAVE_NFSV4_ACL
+	printf(" acl-NFSv4");
+#endif
 }
 
 /*
@@ -217,6 +220,15 @@ get_acls(info)
 	if (is_symlink(info))
 		return (TRUE);
 
+#ifdef	HAVE_FREEBSD_NFSV4_ACL
+	if (acl_to_info(info->f_sname, ACL_TYPE_NFS4, &acl_ace_text)) {
+		if (*acl_ace_text.ps_path != '\0') {
+			info->f_xflags |= XF_ACL_ACE;
+			info->f_acl_ace = acl_ace_text.ps_path;
+		}
+		return (TRUE);
+	}
+#endif
 	if (!acl_to_info(info->f_sname, ACL_TYPE_ACCESS, &acl_access_text))
 		return (FALSE);
 	if (*acl_access_text.ps_path != '\0') {
@@ -263,6 +275,13 @@ acl_to_info(name, type, acltext)
 		if (err == ENOSYS)
 			return (TRUE);
 #endif
+#ifdef	HAVE_FREEBSD_NFSV4_ACL
+		/*
+		 * If ACL type is not NFS4 we continue with POSIX.1e ACLs
+		 */
+		if (type == ACL_TYPE_NFS4 && err == EINVAL)
+			return (FALSE);
+#endif
 		if (!errhidden(E_GETACL, name)) {
 			if (!errwarnonly(E_GETACL, name))
 				xstats.s_getaclerrs++;
@@ -273,7 +292,12 @@ acl_to_info(name, type, acltext)
 		return (FALSE);
 	}
 	seterrno(0);
-	text = acl_to_text(acl, NULL);
+#ifdef	HAVE_FREEBSD_NFSV4_ACL
+	if (type == ACL_TYPE_NFS4)
+		text = acl_to_text_np(acl, NULL, ACL_TEXT_APPEND_ID);
+	else
+#endif
+		text = acl_to_text(acl, NULL);
 	acl_free(acl);
 	if (text == NULL) {
 		if (geterrno() == 0)
@@ -313,6 +337,22 @@ acl_to_info(name, type, acltext)
 			;
 	}
 
+#ifdef	HAVE_FREEBSD_NFSV4_ACL
+	/* remove space fields */
+	if (type == ACL_TYPE_NFS4) {
+		c = text;
+		while ((c = strchr(c, ' ')) != NULL) {
+			char *d = c, *e;
+
+			while (*d && *d == ' ')
+				d++;
+			e = c;
+			while ((*e++ = *d++) != '\0')
+				;
+		}
+	}
+#endif
+
 	/* count fields */
 	for (c = text; *c != '\0'; c++) {
 		if (*c == '\n') {
@@ -320,6 +360,14 @@ acl_to_info(name, type, acltext)
 			entries++;
 		}
 	}
+#ifdef	HAVE_FREEBSD_NFSV4_ACL
+	if (type == ACL_TYPE_NFS4) {
+		if (strcpy_pspace(PS_EXIT, acltext, text) < 0) {
+			acl_free((acl_t)text);
+			return (FALSE);
+		}
+	} else
+#endif
 	if ((entries > 3) || /* > 4 on Solaris? */
 	    (type == ACL_TYPE_DEFAULT && entries >= 3)) {
 		if ((entries * 56) > acltext->ps_size)
@@ -446,6 +494,55 @@ set_acls(info)
 
 	aclps.ps_path = acltext;
 	aclps.ps_size = PATH_MAX;
+
+#ifdef	HAVE_FREEBSD_NFSV4_ACL
+	if (info->f_xflags & XF_ACL_ACE) {
+		ssize_t	len = strlen(info->f_acl_ace) + 2;
+
+		if (len > aclps.ps_size) {
+			aclps.ps_path = NULL;
+			aclps.ps_size = 0;
+			grow_pspace(PS_EXIT, &aclps, len);
+			if (aclps.ps_size <= len) {
+				free_pspace(&aclps);
+				return;
+			}
+		}
+		acl_check_ids(aclps.ps_path, info->f_acl_ace, TRUE);
+
+		if ((acl = acl_from_text(aclps.ps_path)) == NULL) {
+			if (!errhidden(E_BADACL, info->f_name)) {
+				if (!errwarnonly(E_BADACL, info->f_name))
+					xstats.s_badacl++;
+				errmsg("Cannot convert NFSv4 ACL '%s' to internal format for ' %s'.\n",
+				    aclps.ps_path, info->f_name);
+				(void) errabort(E_BADACL, info->f_name, TRUE);
+			}
+		} else {
+			if (acl_set_file(info->f_name, ACL_TYPE_NFS4,
+			    acl) < 0) {
+				/*
+				 * XXX What should we do if errno is
+				 * ENOTSUP/ENOSYS?
+				 */
+				if (!errhidden(E_SETACL, info->f_name)) {
+					if (!errwarnonly(E_SETACL,
+					    info->f_name))
+						xstats.s_setacl++;
+					errmsg("Cannot set NFSv4 ACL '%s' for '%s'.\n",
+					    aclps.ps_path, info->f_name);
+					(void) errabort(E_SETACL, info->f_name,
+					    TRUE);
+				}
+			}
+			acl_free(acl);
+		}
+		if (aclps.ps_path != acltext)
+			free_pspace(&aclps);
+		return;
+	}
+#endif	/* HAVE_FREEBSD_NFSV4_ACL */
+
 	if (info->f_xflags & XF_ACL_ACCESS) {
 		ssize_t	len = strlen(info->f_acl_access) + 2;
 
