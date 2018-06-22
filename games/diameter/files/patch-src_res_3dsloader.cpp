--- src/res/3dsloader.cpp.orig	2008-07-31 11:22:38 UTC
+++ src/res/3dsloader.cpp
@@ -74,7 +74,7 @@ for (i=0; i<MAX_POLYGONS; i++)
 struct stat file_status;
 #endif
 
-if (p_filename=='\0')
+if (p_filename==nullptr || *p_filename=='\0')
 	return(0);
 
 if ((l_file=fopen (p_filename, "rb"))== NULL)
