--- src/task.cpp.orig	Tue Nov  7 03:17:19 2006
+++ src/task.cpp	Thu Mar 15 17:24:14 2007
@@ -46,11 +46,11 @@
 void Task::draw(QPixmap& buffer, int x, int y, int size) {
     if (size >= m_minSize && size <= m_maxSize) {
         if (m_demandsAttention && (m_timerCount == 1)) {
-            KPixmap pix(m_icons.at(size - m_minSize));
+            KPixmap pix(m_icons[size - m_minSize]);
             KPixmapEffect::fade(pix, 0.5, QColor("#ffffff"));
             bitBlt(&buffer, x, y, &pix);            
         } else {
-            bitBlt(&buffer, x, y, &m_icons.at(size - m_minSize));
+            bitBlt(&buffer, x, y, &m_icons[size - m_minSize]);
         }
     }
 }
