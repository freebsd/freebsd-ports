--- fsimageplugin/CompressedFile.cpp.orig	2025-08-10 22:29:50 UTC
+++ fsimageplugin/CompressedFile.cpp
@@ -43,7 +43,7 @@ CompressedFile::CompressedFile( std::string pFilename,
 
 
 CompressedFile::CompressedFile( std::string pFilename, int pMode, size_t n_threads)
-	: hotCache(NULL), error(false), currentPosition(0),
+	: hotCache(), error(false), currentPosition(0),
 	  finished(false), filesize(0), noMagic(false),
 	mutex(Server->createMutex()), n_threads(n_threads), numBlockOffsets(0)
 {
@@ -80,7 +80,7 @@ CompressedFile::CompressedFile(IFile* file, bool openE
 }
 
 CompressedFile::CompressedFile(IFile* file, bool openExisting, bool readOnly, size_t n_threads)
-	: hotCache(NULL), error(false), currentPosition(0),
+	: hotCache(), error(false), currentPosition(0),
 	finished(false), uncompressedFile(file), filesize(0), readOnly(readOnly),
 	noMagic(false), mutex(Server->createMutex()), n_threads(n_threads), numBlockOffsets(0)
 {
