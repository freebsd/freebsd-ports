--- setup/srcconf.c.orig	2009-09-03 06:14:33.000000000 -0400
+++ setup/srcconf.c	2009-09-22 14:52:03.000000000 -0400
@@ -195,7 +195,7 @@
 	{
 	  parms = "";
 	  if (getenv ("OGG_SUPPORT") != NULL)
-	    parms = "-DOGG_SUPPORT";
+	    parms = "-DOGG_SUPPORT -I%%LOCALBASE%%/include";
 	}
 
       if (strcmp (line, "project") == 0)
@@ -913,7 +913,7 @@
   if (config_phpmake)
      fprintf (f, "<?php require getenv(\"PHPMAKE_LIBPATH\") . \"library.php\"; phpmake_makefile_top_rules(); ?>\n");
 
-  fprintf (f, "CC=%s\n", conf.ccomp);
+  fprintf (f, "CC=%s\n", targetcc);
   // fprintf (f, "LD=ld\n");
   fprintf (f, "HOSTCC=%s\n", hostcc);
   fprintf (f, "CPLUSPLUS=%s\n", conf.cplusplus);
