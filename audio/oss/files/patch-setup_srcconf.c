--- setup/srcconf.c.orig	2015-01-28 08:07:32 UTC
+++ setup/srcconf.c
@@ -195,7 +195,7 @@ parse_config (FILE * f, conf_t * conf, c
 	{
 	  parms = "";
 	  if (getenv ("OGG_SUPPORT") != NULL)
-	    parms = "-DOGG_SUPPORT";
+	    parms = "-DOGG_SUPPORT -I%%LOCALBASE%%/include";
 	}
 
       if (strcmp (line, "project") == 0)
@@ -913,7 +913,7 @@ printf("Symlink %s -> %s\n", source, tar
   if (config_phpmake)
      fprintf (f, "<?php require getenv(\"PHPMAKE_LIBPATH\") . \"library.php\"; phpmake_makefile_top_rules(); ?>\n");
 
-  fprintf (f, "CC=%s\n", conf.ccomp);
+  fprintf (f, "CC=%s\n", targetcc);
   // fprintf (f, "LD=ld\n");
   fprintf (f, "HOSTCC=%s\n", hostcc);
   fprintf (f, "CPLUSPLUS=%s\n", conf.cplusplus);
