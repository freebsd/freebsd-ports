--- src/attrib.c.orig	Thu Jan  9 10:55:14 2003
+++ src/attrib.c	Thu Jan  9 10:56:45 2003
@@ -626,6 +626,11 @@
 	fprintf(fp, "delete_tmp_files=ON\n");
 	fprintf(fp, "followup_to=poster\n\n");
 
+	fprintf(fp, _("# in tw* set charset to Big5\n"));
+	fprintf(fp, "scope=tw*\n");
+	fprintf(fp, "mm_network_charset=Big5\n");
+	fprintf(fp, "undeclared_charset=Big5\n");
+
 #if 0 /* FIXME */
 	for_each_group(i) {
 		group = &active[i];
