--- ./config.c.orig	2012-12-04 19:40:15.395225527 +1100
+++ ./config.c	2012-12-04 19:40:38.975104852 +1100
@@ -77,7 +77,7 @@
 	fclose (fp);
 
 	/* Check config settings */
-	if (strnlen(options->cluster_name, MAXLEN)==0)
+	if (strlen(options->cluster_name)==0)
 	{
 		fprintf(stderr, "Cluster name is missing. "
 		        "Check the configuration file.\n");
