--- src/project/internal/exporttype.cpp.orig	2024-02-27 16:37:17 UTC
+++ src/project/internal/exporttype.cpp
@@ -21,6 +21,8 @@
  */
 #include "exporttype.h"
 
+#include <QVariantList>
+
 using namespace mu::project;
 
 ExportTypeList::ExportTypeList()
