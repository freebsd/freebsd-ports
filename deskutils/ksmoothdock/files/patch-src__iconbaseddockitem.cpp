--- src/iconbaseddockitem.cpp.orig	Thu Jun  8 09:25:54 2006
+++ src/iconbaseddockitem.cpp	Thu Mar 15 17:24:14 2007
@@ -86,7 +86,7 @@
         s = m_maxSize;
     }
 
-    return m_icons.at(s - m_minSize);
+    return m_icons[s - m_minSize];
 }
 
 /**
@@ -109,7 +109,7 @@
 
 void IconBasedDockItem::draw(QPixmap& buffer, int x, int y, int size) {
     if (size >= m_minSize && size <= m_maxSize)
-        bitBlt(&buffer, x, y, &m_icons.at(size - m_minSize));
+        bitBlt(&buffer, x, y, &m_icons[size - m_minSize]);
 }
 
 /** 
