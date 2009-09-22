--- setup/srcconf.c.orig	2009-09-03 06:14:33.000000000 -0400
+++ setup/srcconf.c	2009-09-22 14:52:03.000000000 -0400
@@ -195,7 +195,7 @@
 	{
 	  parms = "";
 	  if (getenv ("OGG_SUPPORT") != NULL)
-	    parms = "-DOGG_SUPPORT";
+	    parms = "-DOGG_SUPPORT -I%%PREFIX%%/include";
 	}
 
       if (strcmp (line, "project") == 0)
