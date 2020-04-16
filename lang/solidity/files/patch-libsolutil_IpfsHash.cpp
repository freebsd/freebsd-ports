--- libsolutil/IpfsHash.cpp.orig	2020-04-16 09:14:46 UTC
+++ libsolutil/IpfsHash.cpp
@@ -160,7 +160,7 @@ bytes solidity::util::ipfsHash(string _data)
 
 	Chunks allChunks;
 
-	for (unsigned long chunkIndex = 0; chunkIndex < chunkCount; chunkIndex++)
+	for (size_t chunkIndex = 0; chunkIndex < chunkCount; chunkIndex++)
 	{
 		bytes chunkBytes = asBytes(
 			_data.substr(chunkIndex * maxChunkSize, min(maxChunkSize, _data.length() - chunkIndex * maxChunkSize))
