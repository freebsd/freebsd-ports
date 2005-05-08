--- view.cc.orig	Wed Apr  6 15:14:58 2005
+++ view.cc	Sat May  7 22:35:53 2005
@@ -632,7 +632,7 @@
     m_game_over = true;	//aw???
     m_aborted = true;
 
-    QString text(tr("Game aborted.")+(!msg.isEmpty() ? "\n"+msg : ""));
+    QString text(tr("Game aborted.")+(!msg.isEmpty() ? QString("\n") +msg : QString("")));
     m_status->setText(text);
 
     emit working(false);
