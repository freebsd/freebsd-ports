--- src/project/internal/exporttype.h.orig	2024-01-23 09:35:14 UTC
+++ src/project/internal/exporttype.h
@@ -26,6 +26,10 @@
 
 #include "containers.h"
 
+#include <QList>
+#include <QString>
+#include <QVariantList>
+
 namespace mu::project {
 struct ExportType;
 class ExportTypeList : public QList<ExportType>
