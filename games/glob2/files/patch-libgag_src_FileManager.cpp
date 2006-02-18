--- ./libgag/src/FileManager.cpp.orig	Sat Dec 10 23:25:19 2005
+++ ./libgag/src/FileManager.cpp	Sat Feb 18 09:52:32 2006
@@ -86,13 +86,17 @@
 #endif
 		addDir(".");
 
-		#ifndef WIN32 	
+		#ifndef WIN32
 		#ifndef __APPLE__
 		/* Find own path
 		 * TODO: Make nicer */
-		
+
 		char link[100];
+		#ifdef __FreeBSD__
+		char proc[]="/proc/curproc/file";
+		#else
 		char proc[]="/proc/self/exe";
+		#endif
 		char * pch;
 
 		int linksize = readlink(proc, link, sizeof(link));
@@ -102,17 +106,17 @@
 		}
 		else
 		{
-			assert ((int)sizeof(link) > linksize); 
+			assert ((int)sizeof(link) > linksize);
 			link[linksize] = '\0';
 
-			pch = strrchr(link,'/');	
-			if ( (pch-link) > 0) 
+			pch = strrchr(link,'/');
+			if ( (pch-link) > 0)
 				link[pch-link] = '\0';
 			else
 				link[1] = '\0';
 
-			pch = strrchr(link,'/');	
-			if ( (pch-link) > 0) 
+			pch = strrchr(link,'/');
+			if ( (pch-link) > 0)
 				link[pch-link] = '\0';
 
 			if ((linksize + 13) <= (int)sizeof(link))
