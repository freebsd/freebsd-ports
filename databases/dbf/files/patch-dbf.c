--- dbf.c	Fri Apr 16 08:17:22 2004
+++ dbf.c	Fri Apr 16 15:31:29 2004
@@ -245,11 +245,11 @@
 	int		 dbfhandle;
 	FILE		*output = NULL;
 	int		 header_length, record_length, i;
-	const char	*filename, *export_filename;
+	const char	*filename, *export_filename = NULL;
 	headerMethod	 writeHeader = NULL;
 	lineMethod	 writeLine = printDBF;
 	unsigned char	*record;
-	char *flag_byte;
+	char		 flag_byte;
 
 	if (argc < 2) {
 		fprintf(stderr, "Usage: %s [option][argument] dbf-file, -h for help\n", *argv);
@@ -342,7 +342,7 @@
 	if (verbosity > 0)
 		banner();
 
-	if(0 == strcmp(export_filename, "-"))
+	if(!export_filename || (0 == strcmp(export_filename, "-")))
 		output = stdout;
 	else
 		output = export_open(export_filename);
@@ -372,12 +372,7 @@
 		/* At this point we look if the following data set is deleted */
 		lseek(dbfhandle, rotate2b(db->header_length), SEEK_SET);
 		
-		if ( (flag_byte = malloc(1)) == NULL ) {
-			perror("malloc");
-			exit(1);
-		}  
-		
-		if ( -1 == read(dbfhandle, flag_byte, 1) ) {
+		if ( -1 == read(dbfhandle, &flag_byte, 1) ) {
 			perror("reading Flag Byte");
 			exit(1);
 		}
@@ -389,11 +384,11 @@
 				exit(1);
 			}
 
-			if (*flag_byte == '*' && keep_deleted == 0) {
+			if (flag_byte == '*' && keep_deleted == 0) {
 				fputc('#', output);
 			}
 
-			*flag_byte = *(record + record_length - 1);
+			flag_byte = *(record + record_length - 1);
 			
 			/* automaticly convert options */
 		  	if (convert)
