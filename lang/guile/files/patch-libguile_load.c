--- libguile/load.c.orig	Tue Feb  4 21:05:24 2003
+++ libguile/load.c	Tue Feb  4 21:19:39 2003
@@ -239,6 +239,8 @@
   path = scm_listify (scm_makfrom0str (SCM_SITE_DIR),
 		      scm_makfrom0str (SCM_LIBRARY_DIR),
 		      scm_makfrom0str (SCM_PKGDATA_DIR),
+		      scm_makfrom0str ("%%X11BASE%%/share/guile"),
+		      scm_makfrom0str ("%%LOCALBASE%%/share/guile"),
 		      SCM_UNDEFINED);
 #endif /* SCM_LIBRARY_DIR */
 
