--- tools/fax2ps.c.orig	Sat Mar  5 10:06:08 2005
+++ tools/fax2ps.c	Sun Apr 17 23:20:43 2005
@@ -373,11 +373,12 @@
 	int n;
 	FILE* fd;
 	char buf[16*1024];
+	char temp[1024];
 
-	fd = tmpfile();
+	strcpy(temp, "/tmp/fax2psXXXXXX");
+	fd = fdopen(mkstemp(temp), "w+");
 	if (fd == NULL) {
-	    fprintf(stderr, "Could not create temporary file, exiting.\n");
-	    fclose(fd);
+	    fprintf(stderr, "Could not create temp file \"%s\"\n", temp);
 	    exit(-2);
 	}
 	while ((n = read(fileno(stdin), buf, sizeof (buf))) > 0)
