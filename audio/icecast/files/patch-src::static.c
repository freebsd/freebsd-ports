--- src/static.c
+++ src/static.c
@@ -232,9 +232,7 @@
 void 
 send_file_to_socket (connection_t *con, char *filename)
 {
-	struct stat buf;
 	int mp3file;
-	char *suffix;
 	long length;
 	char buff[BUFSIZE];
 	
