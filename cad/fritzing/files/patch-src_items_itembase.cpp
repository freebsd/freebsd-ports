--- src/items/itembase.cpp.orig	2025-04-02 10:33:24 UTC
+++ src/items/itembase.cpp
@@ -55,6 +55,8 @@ along with Fritzing.  If not, see <http://www.gnu.org/
 #include <QClipboard>
 #include <qmath.h>
 
+#include <cstdint>
+
 /////////////////////////////////
 
 static QRegularExpression NumberMatcher;
@@ -1999,7 +2001,7 @@ void ItemBase::debugInfo2(const QString & msg) const
 	                   .arg(this->viewLayerID())
 	                   .arg(this->viewLayerPlacement())
 	                   .arg(this->wireFlags())
-			   .arg((long) dynamic_cast<const QGraphicsItem *>(this), 0, 16)
+	                   .arg(static_cast<long>(reinterpret_cast<std::uintptr_t>(dynamic_cast<const QGraphicsItem *>(this))), 0, 16)
 	                   .arg(m_viewID)
 	                   .arg(this->zValue())
 	                   .arg(this->pos().x())
