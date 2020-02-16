--- tools/sane-desc.c.orig	2020-02-02 11:58:09 UTC
+++ tools/sane-desc.c
@@ -2816,8 +2816,8 @@ html_print_footer (void)
      "<address>\n"
      "<a href=\"imprint.html\"\n"
      ">Contact</a>\n" "</address>\n" "<font size=-1>\n");
-  printf ("This page was last updated on %s by sane-desc %s from %s\n",
-	  asctime (localtime (&current_time)), SANE_DESC_VERSION, PACKAGE_STRING);
+  printf ("This page was last updated by sane-desc %s from %s\n",
+	  SANE_DESC_VERSION, PACKAGE_STRING);
   printf ("</font>\n");
   printf ("</body> </html>\n");
 }
