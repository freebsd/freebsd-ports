--- libguile/load.c.orig	Sat Dec  7 17:41:32 2002
+++ libguile/load.c	Wed Apr 30 22:55:23 2003
@@ -247,9 +247,11 @@
   SCM path = SCM_EOL;
 
 #ifdef SCM_LIBRARY_DIR
-  path = scm_list_3 (scm_makfrom0str (SCM_SITE_DIR),
+  path = scm_list_5 (scm_makfrom0str (SCM_SITE_DIR),
 		     scm_makfrom0str (SCM_LIBRARY_DIR),
-		     scm_makfrom0str (SCM_PKGDATA_DIR));
+		     scm_makfrom0str (SCM_PKGDATA_DIR),
+		     scm_makfrom0str ("%%X11BASE%%/share/guile"),
+		     scm_makfrom0str ("%%LOCALBASE%%/share/guile"));
 #endif /* SCM_LIBRARY_DIR */
 
   path = scm_internal_parse_path (getenv ("GUILE_LOAD_PATH"), path);
