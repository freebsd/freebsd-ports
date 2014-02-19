--- pimsettingexporter/mail/exportmailjob.h.orig	2013-08-14 09:58:28.333460897 +0000
+++ pimsettingexporter/mail/exportmailjob.h	2013-08-14 10:01:42.142460369 +0000
@@ -18,6 +18,8 @@
 #ifndef ExportMailJob_H
 #define ExportMailJob_H
 
+#include <time.h>
+
 #include "abstractimportexportjob.h"
 #include <KSharedConfig>
 class KUrl;
