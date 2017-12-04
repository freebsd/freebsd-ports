--- src/VBox/Frontends/VirtualBox/src/net/UIDownloaderExtensionPack.cpp.orig	2017-01-17 07:26:50 UTC
+++ src/VBox/Frontends/VirtualBox/src/net/UIDownloaderExtensionPack.cpp
@@ -127,7 +127,7 @@ void UIDownloaderExtensionPack::handleVe
         {
             const QString strFileName = strRecord.section(" *", 1);
             const QString strDownloadedSumm = strRecord.section(" *", 0, 0);
-            if (strFileName == source().fileName())
+            if (strFileName == QFileInfo(source().toString()).fileName())
             {
                 /* Calc the SHA-256 on the bytes, creating a string: */
                 uint8_t abHash[RTSHA256_HASH_SIZE];
