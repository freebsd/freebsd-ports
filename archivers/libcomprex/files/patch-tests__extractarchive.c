--- tests/extractarchive.c.orig	Fri Dec 20 08:03:40 2002
+++ tests/extractarchive.c	Mon Jun 23 13:16:14 2003
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
 
