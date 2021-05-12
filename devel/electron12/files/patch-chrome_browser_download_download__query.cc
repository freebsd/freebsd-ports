--- chrome/browser/download/download_query.cc.orig	2021-01-07 00:36:22 UTC
+++ chrome/browser/download/download_query.cc
@@ -28,7 +28,11 @@
 #include "components/download/public/common/download_item.h"
 #include "components/url_formatter/url_formatter.h"
 #include "content/public/browser/content_browser_client.h"
+#if defined(OS_BSD)
+#include <re2/re2.h>
+#else
 #include "third_party/re2/src/re2/re2.h"
+#endif
 #include "url/gurl.h"
 
 using download::DownloadDangerType;
