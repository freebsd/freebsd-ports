--- include/widgets/plain_text_edit.h.orig	2016-07-30 20:59:16 UTC
+++ include/widgets/plain_text_edit.h
@@ -75,7 +75,7 @@ protected:
       if (show_margin) {
         const QRect rect = event->rect();
         const QFont font = currentCharFormat().font();
-        int x = std::round(QFontMetrics(font).maxWidth() * margin)
+        int x = ::round(QFontMetrics(font).maxWidth() * margin)
               + contentOffset().x()
               + document()->documentMargin();
 
