--- src/project/internal/exporttype.h.orig	2024-12-11 12:43:18 UTC
+++ src/project/internal/exporttype.h
@@ -28,6 +28,10 @@
 
 #include "containers.h"
 
+#include <QList>
+#include <QString>
+#include <QVariantList>
+
 namespace mu::project {
 struct ExportType;
 class ExportTypeList : public QList<ExportType>
