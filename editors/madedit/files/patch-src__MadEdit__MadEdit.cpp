--- ./src/MadEdit/MadEdit.cpp.orig	2012-02-27 11:29:01.012086960 -0800
+++ ./src/MadEdit/MadEdit.cpp	2012-02-27 11:29:01.141087896 -0800
@@ -9739,7 +9739,9 @@
     {
         if(m_EditMode!=emHexMode)
         {
-            memdc.SelectObject(*m_ClientBitmap);
+            if(m_ClientBitmap!=NULL) {
+                memdc.SelectObject(*m_ClientBitmap);
+            }
             memdc.SetFont(*m_TextFont);
 
             // calculate rows to paint
@@ -9917,7 +9919,9 @@
 
                 if(bPaintMark==false)
                 {
-                    markdc.SelectObject(*m_MarkBitmap);
+                    if(m_MarkBitmap!=NULL) {
+                        markdc.SelectObject(*m_MarkBitmap);
+                    }
                     markdc.Blit(0,0,m_ClientWidth,m_ClientHeight, &memdc, 0, 0);
                     bPaintMark=true;
                 }
