--- src/sketch/sketchwidget.cpp.orig	2026-07-28 07:36:38 UTC
+++ src/sketch/sketchwidget.cpp
@@ -43,6 +43,7 @@ along with Fritzing.  If not, see <http://www.gnu.org/
 #include <QRandomGenerator>
 #include <QMimeData>
 
+#include <cstdint>
 #include <limits>
 
 #include "../items/partfactory.h"
@@ -1028,7 +1029,7 @@ void SketchWidget::deleteItemForCommand(long id, bool 
 
 void SketchWidget::deleteItemForCommand(long id, bool deleteModelPart, bool doEmit, bool later) {
 	ItemBase * pitem = findItem(id);
-	// DebugDialog::debug(QString("delete item (1) %1 %2 %3 %4").arg(id).arg(doEmit).arg(m_viewID).arg((long) pitem, 0, 16) );
+	// DebugDialog::debug(QString("delete item (1) %1 %2 %3 %4").arg(id).arg(doEmit).arg(m_viewID).arg(static_cast<long>(reinterpret_cast<std::uintptr_t>(pitem)), 0, 16) );
 	if (pitem) {
 		deleteItem(pitem, deleteModelPart, doEmit, later);
 	}
@@ -1042,7 +1043,7 @@ void SketchWidget::deleteItem(ItemBase * itemBase, boo
 void SketchWidget::deleteItem(ItemBase * itemBase, bool deleteModelPart, bool doEmit, bool later)
 {
 	long id = itemBase->id();
-	DebugDialog::debug(QString("delete item (2) %1 %2 %3 %4").arg(id).arg(itemBase->title()).arg(m_viewID).arg((long) itemBase, 0, 16) );
+	DebugDialog::debug(QString("delete item (2) %1 %2 %3 %4").arg(id).arg(itemBase->title()).arg(m_viewID).arg(static_cast<long>(reinterpret_cast<std::uintptr_t>(itemBase)), 0, 16) );
 
 	// this is a hack to try to workaround a Qt 4.7 crash in QGraphicsSceneFindItemBspTreeVisitor::visit
 	// when using a custom boundingRect, after deleting an item, it still appears on the visit list.
