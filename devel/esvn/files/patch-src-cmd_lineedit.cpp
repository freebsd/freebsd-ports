--- cmd_lineedit.cpp	Sun Aug 22 03:18:28 2004
+++ src/cmd_lineedit.cpp	Tue Aug 24 13:11:50 2004
@@ -29,9 +29,9 @@
 void Cmd_LineEdit::keyPressEvent( QKeyEvent * e )
 {
 	if( ( e->key() == Qt::Key_Up ) && ( pos > 0) )
-		setText(cmd_hist.at(--pos));
+		setText(cmd_hist[--pos]);
 	else if( ( e->key() == Qt::Key_Down ) &&  ( pos + 1 < cmd_hist.size() ) )
-			setText(cmd_hist.at(++pos));
+			setText(cmd_hist[++pos]);
 	else
 		QLineEdit::keyPressEvent(e);
 }
