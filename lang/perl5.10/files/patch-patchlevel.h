$FreeBSD$

--- patchlevel.h.orig	Wed Feb  2 16:45:30 2005
+++ patchlevel.h	Wed Feb  2 16:45:34 2005
@@ -120,6 +120,8 @@ hunk.
 #if !defined(PERL_PATCHLEVEL_H_IMPLICIT) && !defined(LOCAL_PATCH_COUNT)
 static	char	*local_patches[] = {
 	NULL
+	,"SUIDPERLIO0 - fix PERLIO_DEBUG local root exploit (CAN-2005-0155)"
+	,"SUIDPERLIO1 - fix PERLIO_DEBUG buffer overflow (CAN-2005-0156)"
 	,NULL
 };
 
