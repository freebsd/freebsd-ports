--- listcab.cpp.orig	Tue Aug 19 20:42:27 2003
+++ listcab.cpp	Tue Aug 19 20:49:27 2003
@@ -47,13 +47,19 @@
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
@@ -62,10 +68,13 @@
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
