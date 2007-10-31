--- src/CFileData.h.orig	2005-04-25 18:25:38.000000000 +0000
+++ src/CFileData.h	2007-10-31 02:26:03.000000000 +0000
@@ -30,5 +30,5 @@
 	FileData();
 	
 	void swapEndians();
-	void FileData::set(char *filename, Uint32 fSize, Uint32 cSize, Uint32 location);
+	void set(char *filename, Uint32 fSize, Uint32 cSize, Uint32 location);
 };
