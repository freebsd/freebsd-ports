Fix bogus pointer comparison.

--- src/widget/wdisplay.cpp.orig	2013-05-08 23:20:26 UTC
+++ src/widget/wdisplay.cpp
@@ -86,7 +86,7 @@ void WDisplay::setPixmap(int iPos, const
 
 void WDisplay::paintEvent(QPaintEvent *)
 {
-    if (m_pPixmaps>0)
+    if (m_pPixmaps)
     {
         int idx = (int)(m_fValue*(float)(m_iNoPos)/128.);
         // Range check
