--- urbackupserver/FileMetadataDownloadThread.cpp.orig	2025-08-10 22:43:07 UTC
+++ urbackupserver/FileMetadataDownloadThread.cpp
@@ -47,7 +47,7 @@ FileMetadataDownloadThread::FileMetadataDownloadThread
 
 FileMetadataDownloadThread::FileMetadataDownloadThread(const std::string& server_token, std::string metadata_tmp_fn,
 	int backupid, int clientid, bool use_tmpfiles, std::string tmpfile_path)
-	: fc(NULL), server_token(server_token), has_error(false), metadata_tmp_fn(metadata_tmp_fn),
+	: fc(), server_token(server_token), has_error(false), metadata_tmp_fn(metadata_tmp_fn),
 	dry_run(true), backupid(backupid), max_metadata_id(0), clientid(clientid), has_fatal_error(false), has_timeout_error(false),
 	use_tmpfiles(use_tmpfiles), tmpfile_path(tmpfile_path), is_complete(false), is_finished(true), force_start(false)
 {
