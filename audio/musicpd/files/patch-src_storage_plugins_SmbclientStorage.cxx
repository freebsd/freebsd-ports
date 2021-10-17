--- src/storage/plugins/SmbclientStorage.cxx.orig	2021-10-14 13:25:21 UTC
+++ src/storage/plugins/SmbclientStorage.cxx
@@ -186,15 +186,15 @@ SmbclientDirectoryReader::GetInfo([[maybe_unused]] boo
 static std::unique_ptr<Storage>
 CreateSmbclientStorageURI([[maybe_unused]] EventLoop &event_loop, const char *base)
 {
-	if (!StringStartsWithCaseASCII(base, "smb://"))
-		return nullptr;
-
 	SmbclientInit();
 
 	return std::make_unique<SmbclientStorage>(base);
 }
 
+static constexpr const char *smbclient_prefixes[] = { "smb://", nullptr };
+
 const StoragePlugin smbclient_storage_plugin = {
 	"smbclient",
+	smbclient_prefixes,
 	CreateSmbclientStorageURI,
 };
