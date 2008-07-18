--- init.c.orig	2008-03-30 09:33:37.000000000 -0400
+++ init.c	2008-07-17 15:33:42.000000000 -0400
@@ -525,6 +525,8 @@
   pfd = pango_font_description_from_string ("misc fixed 16");
   pfm = pango_context_get_metrics (pc, pfd, pl);
   ipfmgadw = pango_font_metrics_get_approximate_digit_width (pfm);
+/* A misc fixed 16 is not a monospace font! -db */
+#if 0
   if(ipfmgadw/PANGO_SCALE==wcol)
    {
     cursor_offset = 4;
@@ -533,10 +535,11 @@
     pango_font_description_free (pfd);
    }
   else
+#endif
    {
     for(nff=0; nff<2; nff++)
      {
-      for(font_size=10; font_size<=24; font_size++)
+      for(font_size=10; font_size<=32; font_size++)
        {
         pango_font_metrics_unref (pfm);
         pango_font_description_free (pfd);
@@ -545,7 +548,7 @@
         pfd = pango_font_description_from_string (font_desc);
         pfm = pango_context_get_metrics (pc, pfd, pl);
         ipfmgadw = pango_font_metrics_get_approximate_digit_width (pfm);
-        if(ipfmgadw/PANGO_SCALE==wcol)
+        if(ipfmgadw/PANGO_SCALE>=wcol)
          {
           nfound = TRUE;
           ipfmgd = pango_font_metrics_get_descent (pfm);
@@ -562,7 +565,11 @@
     pango_font_metrics_unref (pfm);
     pango_font_description_free (pfd);
     if(nfound)
-     printf("Found a good font [%s]\n", font_desc);
+     {
+      if(ipfmgadw/PANGO_SCALE>wcol)
+        printf("Font may appear squashed due to your screen resolution\n");
+      printf("Found a good font [%s] font_size %d\n", font_desc, font_size);
+     }
     else
      {
       printf("Cannot find a suitable font for your system!\n");
