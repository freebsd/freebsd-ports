--- src/SerialIO-POSIX.cpp.orig	2007-10-09 06:02:14.000000000 +0400
+++ src/SerialIO-POSIX.cpp	2008-08-03 03:11:42.000000000 +0400
@@ -219,11 +219,15 @@
 				bFileNameOkay = false;
 				
 #else
-			if (!strncmp(sdNameList[iEntry]->d_name, "ttyS", 4))
+			if (!strncmp(sdNameList[iEntry]->d_name, "cuad", 4))
 				bFileNameOkay = true;
 
-			if (!strncmp(sdNameList[iEntry]->d_name, "ttyUSB", 6))
+			if (!strncmp(sdNameList[iEntry]->d_name, "cuaU", 4))
 				bFileNameOkay = true;
+
+			if (strstr(sdNameList[iEntry]->d_name, ".init") ||
+				strstr(sdNameList[iEntry]->d_name, ".lock"))
+				bFileNameOkay = false;
 #endif
 
 			if (bFileNameOkay)
