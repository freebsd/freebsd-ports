--- src/kernel/qrichtext.cpp.orig	Fri Apr 25 14:57:22 2003
+++ src/kernel/qrichtext.cpp	Fri Apr 25 14:58:18 2003
@@ -4636,7 +4636,7 @@
 	color.setHsv( h1, s1, ( v1 + v2 ) / 2 );
 	painter.setPen( cg.color( QColorGroup::Text ) );
     } else if ( selection == QTextDocument::IMSelectionText ) {
-	color = cg.color( QColorGroup::Foreground );
+	color = cg.color( QColorGroup::Highlight );
 	painter.setPen( cg.color( QColorGroup::HighlightedText ) );
     } else if ( !hasdoc || document()->invertSelectionText( selection ) ) {
 	painter.setPen( cg.color( QColorGroup::HighlightedText ) );
