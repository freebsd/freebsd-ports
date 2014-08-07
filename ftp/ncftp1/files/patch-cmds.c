--- cmds.c.orig	2014-08-06 20:08:22.000000000 -0400
+++ cmds.c	2014-08-06 20:09:04.000000000 -0400
@@ -90,7 +90,7 @@
 extern struct servent		serv;
 extern struct cmd			cmdtab[];
 extern struct userinfo		uinfo;
-extern FILE					*cin, *cout, *logf;
+extern FILE					*cin, *cout, *logfile;
 extern int					Optind;
 extern char					*Optarg;
 extern int					Optind;
@@ -1352,9 +1352,9 @@
 	if (connected)
 		(void) disconnect(0, NULL);
 	rcode = WriteRecentSitesFile();
-	if (logf != NULL) {
-		(void) fclose(logf);
-		logf = NULL;
+	if (logfile != NULL) {
+		(void) fclose(logfile);
+		logfile = NULL;
 	}
 	return rcode;
 }	/* close_up_shop */
