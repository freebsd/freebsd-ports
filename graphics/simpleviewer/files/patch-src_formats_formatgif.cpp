--- src/formats/formatgif.cpp.orig	2010-08-27 17:57:23 UTC
+++ src/formats/formatgif.cpp
@@ -22,7 +22,11 @@ bool CFormatGif::Load(const char* filena
 	}
 	fclose(m_file);
 
+#if GIFLIB_MAJOR >= 5
+	GifFileType* file	= DGifOpenFileName(filename, NULL);
+#else
 	GifFileType* file	= DGifOpenFileName(filename);
+#endif
 	if(file == 0) {
 		std::cout << "Error Opening GIF image" << std::endl;
 		return false;
@@ -31,7 +35,11 @@ bool CFormatGif::Load(const char* filena
 	int res	= DGifSlurp(file);
 	if(res != GIF_OK || file->ImageCount < 1) {
 		std::cout << "Error Opening GIF image" << std::endl;
+#if GIFLIB_MAJOR == 5 && GIFLIB_MINOR >= 1 || GIFLIB_MAJOR > 5
+		DGifCloseFile(file, NULL);
+#else
 		DGifCloseFile(file);
+#endif
 		return false;
 	}
 
@@ -130,7 +138,11 @@ bool CFormatGif::Load(const char* filena
 //
 //	std::cout << "Record Type" << (int)recordType << std::endl;
 
+#if GIFLIB_MAJOR == 5 && GIFLIB_MINOR >= 1 || GIFLIB_MAJOR > 5
+	DGifCloseFile(file, NULL);
+#else
 	DGifCloseFile(file);
+#endif
 
 	return true;
 }
