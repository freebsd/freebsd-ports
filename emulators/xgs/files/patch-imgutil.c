--- imgutil.c.orig	Wed Oct 15 15:54:20 2003
+++ imgutil.c	Wed Oct 15 15:56:02 2003
@@ -53,8 +53,8 @@
 
 int getSource()
 {
-	printf("
-Enter the source filename below or press RETURN to abort.
+	printf("\n\
+Enter the source filename below or press RETURN to abort.\n\
 : ");
 	fgets(sourcefile,256,stdin);
 	sourcefile[strlen(sourcefile)-1]='\0';
@@ -63,8 +63,8 @@
 
 int getDest()
 {
-	printf("
-Enter the destination filename below or press RETURN to abort.
+	printf("\n\
+Enter the destination filename below or press RETURN to abort.\n\
 : ");
 	fgets(destfile,256,stdin);
 	destfile[strlen(destfile)-1]='\0';
@@ -82,10 +82,10 @@
 	char	last;
 	int	size;
 
-	printf("
-Enter a size for this image in bytes. You may also specify the size in
-kilobytes or megabytes by adding a 'K' or 'M' to the end of your input.
-You may enter any size between 16K and 32M.  To abort, just press RETURN.
+	printf("\n\
+Enter a size for this image in bytes. You may also specify the size in\n\
+kilobytes or megabytes by adding a 'K' or 'M' to the end of your input.\n\
+You may enter any size between 16K and 32M.  To abort, just press RETURN.\n\
 : ");
 	fgets(buffer,256,stdin);
 	if (!strlen(buffer)) return 0;
