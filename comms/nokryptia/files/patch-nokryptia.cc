--- src/nokryptia.cc.orig	2013-11-17 23:12:21.000000000 +0800
+++ src/nokryptia.cc	2013-11-17 23:14:38.000000000 +0800
@@ -20,7 +20,7 @@
  */
  
 #include <stdio.h>
-#include <iostream.h>
+#include <iostream>
 #include <string.h>
 #include <getopt.h>
 #include "config.h"
@@ -40,21 +40,21 @@ int    verbose;
 int    action;     /* 1 for upload, 2 for download */
 
 void writeHelpMessage(const char * progname) {
-	cout << PACKAGE << " version " << VERSION
-	     << " copyright by Roel Derickx" << endl
+    std::cout << PACKAGE << " version " << VERSION
+	     << " copyright by Roel Derickx" << std::endl
 	     << "THIS SOFTWARE COMES WITH ABSOLUTELY NO WARRANTY! "
-	     << "USE AT YOUR OWN RISK!" << endl << endl
-	     << "Usage:" << endl
-	     << "   " << progname << " [options] file" << endl
-	     << "Options:" << endl
-	     << "   -u               convert mp3 into lse for upload" << endl
-	     << "   -d               convert lse into mp3 for download" << endl
-	     << "   -a <artistname>  set artist to artistname" << endl
-	     << "   -t <songtitle>   set title to songtitle" << endl
-	     << "   -o <directory>   directory to where output files should be written" << endl
-	     << "   -v               be verbose" << endl
-	     << "   -h               print this help screen" << endl
-	     << "See the man page for more information" << endl;
+	     << "USE AT YOUR OWN RISK!" << std::endl << std::endl
+	     << "Usage:" << std::endl
+	     << "   " << progname << " [options] file" << std::endl
+	     << "Options:" << std::endl
+	     << "   -u               convert mp3 into lse for upload" << std::endl
+	     << "   -d               convert lse into mp3 for download" << std::endl
+	     << "   -a <artistname>  set artist to artistname" << std::endl
+	     << "   -t <songtitle>   set title to songtitle" << std::endl
+	     << "   -o <directory>   directory to where output files should be written" << std::endl
+	     << "   -v               be verbose" << std::endl
+	     << "   -h               print this help screen" << std::endl
+	     << "See the man page for more information" << std::endl;
 }
 
 /*
@@ -83,7 +83,7 @@ int parseInputFiles(int argc, char *argv
 	/* also remove the path from infilename */
 
 	if (optind >= argc) {
-		cout << "No input file given!" << endl;
+        std::cout << "No input file given!" << std::endl;
 		return 1;
 	}
 	strcpy(infilename, argv[optind++]);
@@ -104,15 +104,15 @@ int parseInputFiles(int argc, char *argv
 	switch (action) {
 	case 1:
 		if (looknchange(outfilename,".mp3",".lse") != 0) {
-			cout << "Input file must have mp3 "
-			     << "extension!" << endl;
+            std::cout << "Input file must have mp3 "
+			     << "extension!" << std::endl;
 			return 1;
 		}
 		break;
 	case 2:
 		if (looknchange(outfilename,".lse",".mp3") != 0) {
-			cout << "Input file must have lse "
-			     << "extension!" << endl;
+            std::cout << "Input file must have lse "
+			     << "extension!" << std::endl;
 			return 1;
 		}
 		break;
@@ -167,7 +167,7 @@ int parseOptions(int argc, char * argv[]
 			strcat(outfilename,"\0");
 			break;
 		default:
-			cout << "Unknown option " << optopt << endl;
+            std::cout << "Unknown option " << optopt << std::endl;
 		} /* end of switch */
 	} /* end of while */
 
@@ -198,9 +198,9 @@ void makeTag(char * artist, char * title
 	int lengthTitle  = strlen(title);
 
 	if (verbose) {
-		cout << "Writing tag to output :" << endl;
-		cout << "artistname = " << artist << endl;
-		cout << "songtitle  = " << title << endl;
+        std::cout << "Writing tag to output :" << std::endl;
+        std::cout << "artistname = " << artist << std::endl;
+        std::cout << "songtitle  = " << title << std::endl;
 	}
 
 	/* allocate memory */
@@ -235,7 +235,7 @@ void makeHeader() {
 	char * buf;
 	int i;
 
-	if (verbose) cout << "Writing LockStream key to output" << endl;
+	if (verbose) std::cout << "Writing LockStream key to output" << std::endl;
 
 	/* allocate memory */
 	buf = new char[512];
@@ -266,8 +266,8 @@ int readAndTestHeader() {
 	char * buf;
 
 	if (verbose) {
-		cout << "Testing if the lse file is not written by "
-		     << "the Nokia Audio Manager" << endl;
+        std::cout << "Testing if the lse file is not written by "
+		     << "the Nokia Audio Manager" << std::endl;
 	}
 	
 	/* allocate memory */
@@ -276,7 +276,7 @@ int readAndTestHeader() {
 
 	bread = fread(buf,1,896,infile);
 	if (bread != 896) {
-		cout << "Input file is too small!" << endl;
+        std::cout << "Input file is too small!" << std::endl;
 		return 0;
 	}
 	
@@ -301,7 +301,7 @@ void copyData() {
 	int bread, bwritten;
 	char * buf;
 
-	if (verbose) cout << "Writing data to output" << endl;
+	if (verbose) std::cout << "Writing data to output" << std::endl;
 
 	/* allocate memory */
 	buf = new char[COPYBUFSIZE];
@@ -347,8 +347,8 @@ int main(int argc, char * argv[]) {
 	
 	/* open the infile */
 	if ((infile = fopen(infilename,"rb")) == NULL) {
-		cout << infilename 
-		     << ": No such file or directory" << endl;
+        std::cout << infilename 
+		     << ": No such file or directory" << std::endl;
 		
 		cleanUpMemory();
 		
@@ -358,10 +358,10 @@ int main(int argc, char * argv[]) {
 	
 	/* open the outfile */
 	if ((outfile = fopen(outfilename,"wb")) == NULL) {
-		cout << "An error occured while opening " 
-		     << outfilename << " for writing." << endl
+        std::cout << "An error occured while opening " 
+		     << outfilename << " for writing." << std::endl
 		     << "Do you have write permission "
-		     << "in this directory?" << endl;
+		     << "in this directory?" << std::endl;
 		
 		cleanUpMemory();
 		
@@ -383,9 +383,9 @@ int main(int argc, char * argv[]) {
 			copyData();
 		}
 		else {
-			cout << "This file was encrypted by the "
-			     << "official nokia program." << endl
-			     << "Unable to decrypt!" << endl;
+            std::cout << "This file was encrypted by the "
+			     << "official nokia program." << std::endl
+			     << "Unable to decrypt!" << std::endl;
 		}
 	}
 	
