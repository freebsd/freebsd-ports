--- fileservplugin/FileMetadataPipe.cpp.orig	2025-08-10 22:44:37 UTC
+++ fileservplugin/FileMetadataPipe.cpp
@@ -71,7 +71,7 @@ FileMetadataPipe::FileMetadataPipe( IPipe* pipe, const
 #endif
 	metadata_state(MetadataState_Wait),
 		errpipe(Server->createMemoryPipe()),
-	metadata_file(NULL)
+	metadata_file()
 {
 	metadata_buffer.resize(4096);
 	init();
