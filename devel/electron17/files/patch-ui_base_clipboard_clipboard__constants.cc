--- ui/base/clipboard/clipboard_constants.cc.orig	2022-05-11 07:17:06 UTC
+++ ui/base/clipboard/clipboard_constants.cc
@@ -20,7 +20,7 @@ const char kMimeTypePNG[] = "image/png";
 // Used for image drag & drop from LaCrOS.
 const char kMimeTypeOctetStream[] = "application/octet-stream";
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_FUCHSIA)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_FUCHSIA) || defined(OS_BSD)
 const char kMimeTypeLinuxUtf8String[] = "UTF8_STRING";
 const char kMimeTypeLinuxString[] = "STRING";
 const char kMimeTypeLinuxText[] = "TEXT";
