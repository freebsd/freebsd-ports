--- include/gui/plain_text_edit.h.orig	2015-11-29 14:07:34 UTC
+++ include/gui/plain_text_edit.h
@@ -73,7 +73,7 @@ protected:
       if (show_margin) {
         const QRect rect = event->rect();
         const QFont font = currentCharFormat().font();
-        int x = std::round(QFontMetrics(font).maxWidth() * margin)
+        int x = ::round(QFontMetrics(font).maxWidth() * margin)
               + contentOffset().x()
               + document()->documentMargin();
 
