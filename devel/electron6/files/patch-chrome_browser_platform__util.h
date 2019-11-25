--- chrome/browser/platform_util.h.orig	2019-09-10 10:42:29 UTC
+++ chrome/browser/platform_util.h
@@ -41,7 +41,7 @@ enum OpenOperationResult {
 enum OpenItemType {
   OPEN_FILE,
   OPEN_FOLDER,
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   SHOW_ITEM_IN_FOLDER
 #endif
 };
