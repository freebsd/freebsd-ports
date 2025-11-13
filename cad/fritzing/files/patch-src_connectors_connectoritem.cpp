--- src/connectors/connectoritem.cpp.orig	2025-04-02 10:33:24 UTC
+++ src/connectors/connectoritem.cpp
@@ -204,13 +204,15 @@ parts editor support
 #include <QBrush>
 #include <QPen>
 #include <QColor>
-#include <limits>
 #include <QSet>
 #include <QToolTip>
 #include <QBitmap>
 #include <QApplication>
 #include <qmath.h>
 
+#include <cstdint>
+#include <limits>
+
 #include "../sketch/infographicsview.h"
 #include "../debugdialog.h"
 #include "bus.h"
@@ -490,7 +492,7 @@ ConnectorItem * ConnectorItem::removeConnection(ItemBa
 			restoreColor(visited);
 			if (itemBase) {
 				DebugDialog::debug(QString("remove from:%1 to:%2 count%3")
-						   .arg((long) this, 0, 16)
+						   .arg(static_cast<long>(reinterpret_cast<std::uintptr_t>(this)), 0, 16)
 						   .arg(itemBase->modelPartShared()->title())
 						   .arg(m_connectedTo.count()) );
 			}
