--- init.c.orig	2008-05-27 11:46:25.000000000 -0400
+++ init.c	2008-05-27 11:47:49.000000000 -0400
@@ -525,6 +525,8 @@
   pfd = pango_font_description_from_string ("misc fixed 16");
   pfm = pango_context_get_metrics (pc, pfd, pl);
   ipfmgadw = pango_font_metrics_get_approximate_digit_width (pfm);
+/* A misc fixed 16 is not a monospace font! -db */
+#if 0
   if(ipfmgadw/PANGO_SCALE==wcol)
    {
     cursor_offset = 4;
@@ -533,6 +535,7 @@
     pango_font_description_free (pfd);
    }
   else
+#endif
    {
     for(nff=0; nff<2; nff++)
      {
