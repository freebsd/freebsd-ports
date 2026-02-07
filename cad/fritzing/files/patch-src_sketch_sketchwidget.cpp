--- src/sketch/sketchwidget.cpp.orig	2025-10-07 13:46:45 UTC
+++ src/sketch/sketchwidget.cpp
@@ -42,6 +42,7 @@ along with Fritzing.  If not, see <http://www.gnu.org/
 #include <QRandomGenerator>
 #include <QMimeData>
 
+#include <cstdint>
 #include <limits>
 
 #include "../items/partfactory.h"
@@ -1009,7 +1010,7 @@ void SketchWidget::deleteItemForCommand(long id, bool 
 
 void SketchWidget::deleteItemForCommand(long id, bool deleteModelPart, bool doEmit, bool later) {
 	ItemBase * pitem = findItem(id);
-	// DebugDialog::debug(QString("delete item (1) %1 %2 %3 %4").arg(id).arg(doEmit).arg(m_viewID).arg((long) pitem, 0, 16) );
+	// DebugDialog::debug(QString("delete item (1) %1 %2 %3 %4").arg(id).arg(doEmit).arg(m_viewID).arg(static_cast<long>(reinterpret_cast<std::uintptr_t>(pitem)), 0, 16) );
 	if (pitem) {
 		deleteItem(pitem, deleteModelPart, doEmit, later);
 	}
@@ -1023,7 +1024,7 @@ void SketchWidget::deleteItem(ItemBase * itemBase, boo
 void SketchWidget::deleteItem(ItemBase * itemBase, bool deleteModelPart, bool doEmit, bool later)
 {
 	long id = itemBase->id();
-	DebugDialog::debug(QString("delete item (2) %1 %2 %3 %4").arg(id).arg(itemBase->title()).arg(m_viewID).arg((long) itemBase, 0, 16) );
+	DebugDialog::debug(QString("delete item (2) %1 %2 %3 %4").arg(id).arg(itemBase->title()).arg(m_viewID).arg(static_cast<long>(reinterpret_cast<std::uintptr_t>(itemBase)), 0, 16) );
 
 	// this is a hack to try to workaround a Qt 4.7 crash in QGraphicsSceneFindItemBspTreeVisitor::visit
 	// when using a custom boundingRect, after deleting an item, it still appears on the visit list.
@@ -1384,7 +1385,7 @@ long SketchWidget::createWire(ConnectorItem * from, Co
 	                   .arg(newID)
 	                   .arg(fromPos.x()).arg(fromPos.y())
 	                   .arg(toPos.x()).arg(toPos.y())
-	                   .arg(wireFlags)
+	                   .arg(wireFlags.toInt())
 	                   .arg(from->attachedToTitle()).arg(from->connectorSharedID())
 	                   .arg(to->attachedToTitle()).arg(to->connectorSharedID())
 	                   .arg(m_viewID)
