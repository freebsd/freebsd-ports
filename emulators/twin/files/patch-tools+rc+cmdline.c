$NetBSD: patch-af,v 1.1.1.1 2001/05/15 09:46:37 agc Exp $

--- tools/rc/cmdline.c.orig	Wed Aug 11 01:34:18 1999
+++ tools/rc/cmdline.c	Sun May 13 10:09:31 2001
@@ -61,7 +61,7 @@
 extern char cpp_module_name[];
 extern char libentry_name[];
 extern char tbl_name[];
-static char *system_include_path[1] = { STDINC };
+static char *system_include_path[2] = { STDINC, __INCPATH__ };
 static int n_system_include_path = sizeof(system_include_path) / 
 				   sizeof(*system_include_path);
 static char **user_include_path = NULL;
