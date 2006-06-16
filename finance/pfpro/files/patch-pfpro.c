--- pfpro.c.orig	Fri Jun 16 00:37:48 2006
+++ pfpro.c	Fri Jun 16 01:01:27 2006
@@ -65,6 +65,9 @@
 	int     parmLen;
 
 
+	/* Set default value of PFPRO_CERT_PATH */
+	setenv("PFPRO_CERT_PATH","%%PREFIX%%/etc/pfpro/certs",0);
+
     if ((argc == 2) && (!strcmp(argv[1],"-i"))) {
         /* read input from stdin */
         if (!fgets(ibuf,sizeof(ibuf),stdin)) {
