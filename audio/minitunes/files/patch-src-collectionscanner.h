--- src/collectionscanner.h.orig	2010-07-05 18:02:28.000000000 +0800
+++ src/collectionscanner.h	2010-07-06 16:08:43.000000000 +0800
@@ -6,8 +6,8 @@
 #include "model/album.h"
 
 // TagLib
-#include "fileref.h"
-#include "tag.h"
+#include "taglib/fileref.h"
+#include "taglib/tag.h"
 
 class Tags {
 
