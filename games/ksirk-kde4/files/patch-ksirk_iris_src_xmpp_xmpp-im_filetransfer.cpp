--- ksirk/iris/src/xmpp/xmpp-im/filetransfer.cpp.orig	2018-08-29 15:45:06 UTC
+++ ksirk/iris/src/xmpp/xmpp-im/filetransfer.cpp
@@ -396,7 +396,7 @@ FileTransfer *FileTransferManager::takeI
 
 bool FileTransferManager::isActive(const FileTransfer *ft) const
 {
-	return d->list.contains(const_cast<FileTransfer*>(ft)) > 0;
+	return bool(d->list.contains(const_cast<FileTransfer*>(ft)));
 }
 
 void FileTransferManager::pft_incoming(const FTRequest &req)
