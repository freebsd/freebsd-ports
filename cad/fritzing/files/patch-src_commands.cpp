Fix build with Qt 6.10.1. The QString::arg() method no longer accepts
implicit conversions. [1]

[1] https://doc.qt.io/qt-6/qstring.html#arg-2

--- src/commands.cpp.orig	2025-10-07 13:46:45 UTC
+++ src/commands.cpp
@@ -509,7 +509,7 @@ QString FlipItemCommand::getParamString() const {
 	       + BaseCommand::getParamString() +
 	       QString(" id:%1 by:%2")
 	       .arg(m_itemID)
-	       .arg(m_orientation);
+	       .arg(static_cast<int>(m_orientation));
 }
 
 /////////////////////////////////////////////////////////////////////////////////////////////////////////////////
@@ -1830,7 +1830,7 @@ QString RotateFlipLabelCommand::getParamString() const
 	}
 	
 	result += QString(" id:%1 degrees:%2 orientation:%3")
-	          .arg(m_itemID).arg(m_degrees).arg(m_orientation);
+	          .arg(m_itemID).arg(m_degrees).arg(static_cast<int>(m_orientation));
 	
 	return result;
 }
