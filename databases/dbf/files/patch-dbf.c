--- dbf.c.orig	Thu Nov 20 05:22:03 2003
+++ dbf.c	Fri Apr  2 17:01:43 2004
@@ -341,7 +341,7 @@
 	if (verbosity > 0)
 		banner();
 
-	if(0 == strcmp(export_filename, "-"))
+	if(!export_filename || (0 == strcmp(export_filename, "-")))
 		output = stdout;
 	else
 		output = export_open(export_filename);
@@ -357,6 +357,7 @@
 		exit(1);
 
 	if (writeLine) {
+		char *flag_byte;
 		if ((record = malloc(record_length + 1)) == NULL)	{
 			perror("malloc"); exit(1);
 		}
@@ -369,7 +370,6 @@
 		//lseek(dbfhandle, rotate2b(db->header_length) + 1, SEEK_SET);
 		
 		/* At this point we look if the following data set is deleted */		
-		char *flag_byte;
 		lseek(dbfhandle, rotate2b(db->header_length), SEEK_SET);
 		
 		if ( (flag_byte = malloc(1)) == NULL ) {
