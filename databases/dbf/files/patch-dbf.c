--- dbf.c.orig	Tue Nov 11 16:48:07 2003
+++ dbf.c	Tue Nov 11 16:48:19 2003
@@ -315,6 +315,7 @@
 		exit(1);
 
 	if (writeLine) {
+		char *flag_byte;
 		if ((record = malloc(record_length + 1)) == NULL)	{
 			perror("malloc"); exit(1);
 		}
@@ -327,7 +328,6 @@
 		//lseek(dbfhandle, rotate2b(db->header_length) + 1, SEEK_SET);
 		
 		/* At this point we look if the following data set is deleted */		
-		char *flag_byte;
 		lseek(dbfhandle, rotate2b(db->header_length), SEEK_SET);
 		
 		if ( (flag_byte = malloc(1)) == NULL ) {
