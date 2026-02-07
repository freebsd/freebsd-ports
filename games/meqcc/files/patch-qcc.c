--- qcc.c.orig	2012-02-06 23:25:07.000000000 +0800
+++ qcc.c	2012-02-06 23:27:08.000000000 +0800
@@ -7,7 +7,7 @@
 
 #include <time.h>
 #include <stdio.h>
-#include <io.h> //lseek, close, filelength
+#include <unistd.h> //lseek, close, filelength
 #if defined(WIN32)|defined(_WIN32)|defined(__NT__)|defined(__WINDOWS__)|defined(__WINDOWS_386__)
 #include <direct.h> //mkdir
 #endif
@@ -1519,7 +1519,7 @@
 main
 =================
 */
-void main (int argc, char **argv)
+int main (int argc, char **argv)
 {
 	char *src;
 	char filename[1024];
@@ -1549,7 +1549,7 @@
 		Log_Print("-?                display command line options\n");
 		Log_Print("-h                \"\n");
 		Log_Print("-help             \"\n");
-		return;
+		return EXIT_SUCCESS;
 	} //end if
 
 	CMDPrecompilerDefinitions();
@@ -1628,4 +1628,6 @@
 	BspModels();
 	//report / copy the data files
 	CopyFiles();
+
+	return EXIT_SUCCESS;
 } //end of the function main
