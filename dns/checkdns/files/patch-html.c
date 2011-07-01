--- ./html.c.orig	2011-07-01 03:29:42.000000000 +0200
+++ ./html.c	2011-07-01 03:29:52.000000000 +0200
@@ -58,7 +58,7 @@
 	fprintf(fd, "<br>\n");
 
 	fprintf(fd, "<br>\n");
-	fprintf(fd, "<table width=\"100%\" border=\"1\" cellspacing=\"0\" cellpadding=\"0\" class=\"domains\">\n");
+	fprintf(fd, "<table width=\"100%%\" border=\"1\" cellspacing=\"0\" cellpadding=\"0\" class=\"domains\">\n");
 	fprintf(fd, "  <tr align=\"left\" valign=\"middle\">\n");
 	fprintf(fd, "    <td class=\"table_header\">&nbsp;%s</td>\n", l_no);
 	fprintf(fd, "    <td class=\"table_header\">&nbsp;%s</td>\n", l_domain);
