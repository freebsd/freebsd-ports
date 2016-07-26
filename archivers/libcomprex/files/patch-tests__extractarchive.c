--- tests/extractarchive.c.orig	2002-12-19 23:03:40 UTC
+++ tests/extractarchive.c
@@ -37,7 +37,9 @@
 void
 __extractprogress(CxArchive *archive, CxFile *file, size_t onFile, size_t fileCount)
 {
-	static int first_file = 0, last_file = 1;
+	static int first_file, last_file;
+	first_file = 0;
+	last_file = 1;
   	if (first_file++ == 0)
     		fprintf(stdout, "Extracting archive:    %s\n", cxGetArchiveFileName(archive));
 
