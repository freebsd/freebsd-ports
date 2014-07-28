--- h2ps.c.bak	Sun Sep 13 17:59:29 1998
+++ h2ps.c	Sun Sep 13 18:02:18 1998
@@ -233,6 +233,12 @@
   fputs("%%Creator: h2ps\n", out);
   fprintf(out, "%%%%CreationDate: %s\n", date_str);
   fputs("%%Pages: (atend)\n", out);
+  fputs("%%PageOrder: Ascend\n", out);
+  fputs("%%DocumentData: Clean7Bit\n", out);
+  if (page_width==595)		/* A4-sized */
+    fputs("%%DocumentPaperSizes: A4\n", out);
+  if (page_width==612)		/* Letter-sized */
+    fputs("%%DocumentPaperSizes: Letter\n", out);
   fputs("%%EndComments\n", out);
   
   npsr_insert_resource(out, NPSR_FONT, "n3f-5");
