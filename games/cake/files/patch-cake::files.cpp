--- cake/files.cpp.orig	Sat Jul 17 20:36:55 2004
+++ cake/files.cpp	Sat Jul 17 20:40:54 2004
@@ -772,7 +772,6 @@
 
 		if (handle == NULL)
 		{
-			closedir(handle);
 			gConsole->Insertln("^1handle == NULL: %d - %s", errno, strerror(errno));
 			if (temp_pat) delete [] temp_pat;
 			temp_pat = NULL;
@@ -860,7 +859,6 @@
 
 		if (handle == NULL)
 		{
-			closedir(handle);
 			gConsole->Insertln("^1handle == NULL: %d - %s", errno, strerror(errno));
 			if (temp_pat) delete [] temp_pat;
 			temp_pat = NULL;
