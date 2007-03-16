--- src/desktopselector.cpp.orig	Thu Nov 16 05:33:29 2006
+++ src/desktopselector.cpp	Thu Mar 15 17:24:14 2007
@@ -45,7 +45,7 @@
 
 void DesktopSelector::draw(QPixmap& buffer, int x, int y, int size) {
     if (size >= m_minSize && size <= m_maxSize) {
-        bitBlt(&buffer, x, y, &m_icons.at(size - m_minSize));
+        bitBlt(&buffer, x, y, &m_icons[size - m_minSize]);
 
         QPainter p(&buffer);
         if (KWin::currentDesktop() == m_targetDesktop)
