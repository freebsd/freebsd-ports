--- src/desktop/khangmanview.cpp.orig	2018-08-28 11:03:47 UTC
+++ src/desktop/khangmanview.cpp
@@ -510,7 +510,7 @@ void KHangManView::slotTry()
 
         int  x = 0;
         int  y = 0;
-        if (m_missedLetters.contains(guess) > 0) {
+        if (m_missedLetters.contains(guess)) {
             // FIXME: popup should be better placed.
 
             QPoint abspos = popup->pos();
@@ -527,7 +527,7 @@ void KHangManView::slotTry()
             m_letterInput->setEnabled(false);
         }
 
-        if (goodWord.contains(guess) > 0) {
+        if (goodWord.contains(guess)) {
             point = m_theme->goodWordPos(size(), popup->pos());
             
             QTimer::singleShot( Prefs::missedTimer() * 1000,
