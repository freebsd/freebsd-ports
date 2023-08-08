- workarounf for https://github.com/cdcseacave/openMVS/issues/910

--- libs/MVS/DepthMap.cpp.orig	2022-11-30 10:06:45 UTC
+++ libs/MVS/DepthMap.cpp
@@ -2036,9 +2036,9 @@ bool MVS::ImportDepthDataRaw(const String& fileName, S
 	// read image file name
 	STATIC_ASSERT(sizeof(String::value_type) == sizeof(char));
 	uint16_t nFileNameSize;
-	fread(&nFileNameSize, sizeof(uint16_t), 1, f);
+	fread((void*)&nFileNameSize, sizeof(uint16_t), 1, f);
 	imageFileName.resize(nFileNameSize);
-	fread(imageFileName.data(), sizeof(char), nFileNameSize, f);
+	fread((void*)imageFileName.data(), sizeof(char), nFileNameSize, f);
 
 	// read neighbor IDs
 	STATIC_ASSERT(sizeof(uint32_t) == sizeof(IIndex));
