--- src/attrib.c.orig	Wed Aug 20 19:19:52 2003
+++ src/attrib.c	Wed Aug 20 19:23:06 2003
@@ -687,6 +687,11 @@
 		fprintf(fp, "post_proc_type=%d\n", POST_PROC_YES);
 		fprintf(fp, "delete_tmp_files=ON\n");
 		fprintf(fp, "followup_to=poster\n\n");
+
+		fprintf(fp, _("# set charset to Big5 in all newsgroups\n"));
+		fprintf(fp, "scope=*\n");
+		fprintf(fp, "mm_network_charset=Big5\n");
+		fprintf(fp, "undeclared_charset=Big5\n");
 	} else {
 		char *ptr;
 		char buf[LEN];
