--- sources/titleblock/templateview.h.orig	2026-01-28 12:19:13 UTC
+++ sources/titleblock/templateview.h
@@ -20,6 +20,8 @@
 #include "../titleblocktemplate.h"
 
 #include <QGraphicsView>
+#include <QGraphicsGridLayout>
+#include <QGraphicsLayoutItem>
 class HelperCell;
 class SplittedHelperCell;
 class TitleBlockTemplateCommand;
