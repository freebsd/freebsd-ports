--- urbackupserver/ClientMain.cpp.orig	2025-08-10 22:37:26 UTC
+++ urbackupserver/ClientMain.cpp
@@ -107,7 +107,7 @@ ClientMain::ClientMain(IPipe *pPipe, FileClient::SAddr
 ClientMain::ClientMain(IPipe *pPipe, FileClient::SAddrHint pAddr, const std::string &pName,
 	const std::string& pSubName, const std::string& pMainName, int filebackup_group_offset, bool internet_connection,
 	bool use_file_snapshots, bool use_image_snapshots, bool use_reflink)
-	: internet_connection(internet_connection), server_settings(NULL), client_throttler(NULL),
+	: internet_connection(internet_connection), server_settings(), client_throttler(NULL),
 	  use_file_snapshots(use_file_snapshots), use_image_snapshots(use_image_snapshots), use_reflink(use_reflink),
 	  backup_dao(NULL), client_updated_time(0), continuous_backup(NULL),
 	  clientsubname(pSubName), filebackup_group_offset(filebackup_group_offset), needs_authentification(false),
