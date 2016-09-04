--- wolflabel.cpp.orig	2010-01-13 21:33:08 UTC
+++ wolflabel.cpp
@@ -24,6 +24,7 @@
 #include <QtGui/QGraphicsItemAnimation>
 #include <QtGui/QGraphicsSceneResizeEvent>
 #include <QtGui/QLabel>
+#include <QtCore/qmath.h>
 
 #include <KIO/Job>
 #include <KIO/NetAccess>
@@ -195,7 +196,7 @@ void WolfLabel::paint(QPainter *painter,
                     m_animation->setPropertyName("xOffset");
                     m_animation->setTargetObject(this);
                 }
-                m_animation->setDuration((2 * abs(x) + SPACING) * 150);
+                m_animation->setDuration((2 * qFabs(x) + SPACING) * 150);
                 m_animation->setNewStartValue(x  - SPACING);
                 m_animation->setNewEndValue(SPACING);
                 if (m_animation->state() != QAbstractAnimation::Running) {
