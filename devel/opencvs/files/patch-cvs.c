--- cvs.c.orig	2008-06-21 17:39:15.000000000 +0200
+++ cvs.c	2010-06-08 20:18:08.000000000 +0200
@@ -70,7 +70,7 @@
 struct cvs_cmd *cmdp;			/* struct of command we are running */
 
 int		cvs_getopt(int, char **);
-__dead void	usage(void);
+void	usage(void);
 static void	cvs_read_rcfile(void);
 
 struct cvs_wklhead temp_files;
@@ -122,7 +122,7 @@
 		cvs_ent_close(current_list, ENT_SYNC);
 }
 
-__dead void
+void
 usage(void)
 {
 	(void)fprintf(stderr,
