--- listcab.cpp.orig	1999-10-24 12:11:38 UTC
+++ listcab.cpp
@@ -8,8 +8,8 @@
 #include <stdio.h>
 #include <string.h>
 //#include <iomanip.h>
-#include <fstream.h>
-#include <iostream.h>
+#include <fstream>
+#include <iostream>
 #include "cftypes.h"
 #include "cfheader.h"
 #include "cffolder.h"
@@ -19,6 +19,10 @@
 #include "cfreader.h"
 #include "cfcreate.h"
 
+using std::endl;
+using std::cout;
+using std::cerr;
+
 ////////////////////////////////////////****************************************
 
 void display_header_info(cabinet_header& cfh);
@@ -47,13 +51,19 @@ int main(int argc, char *argv[])
 			cerr << "New Folder Error: " << retval << endl;
 			return 1;
 		}
-
+		int n;
 		do{
 			cout << "Enter filename: ";
-			gets(filename);
-
-			if(strlen(filename) > 0)
+			fgets(filename, 256, stdin);
+			n = strlen (filename);
+			
+			if (n == 1 && filename[0] == '\n')
+				n = 0;
+			
+			if(n > 0)
 			{
+				if (filename[n-1] == '\n')
+					filename[n-1] = '\0';
 				if((retval = cab.add_file(filename)) != OK)
 				{
 					perror("read");
@@ -62,10 +72,13 @@ int main(int argc, char *argv[])
 					return 1;
 				}
 			}
-		}while(strlen(filename) > 0);
+		}while(n > 0);
 
 		cout << "Enter filename for cabinet: ";
-		gets(filename);
+		fgets(filename, 256, stdin);
+		n = strlen (filename);
+		if (n > 0 && filename[n-1] == '\n')
+			filename[n-1] = '\0';
 
 		if((retval = cab.close(filename)) != OK)
 		{
