--- knotes/knote.cpp	2002/06/17 20:23:11	1.61
+++ knotes/knote.cpp	2002/07/04 08:51:19	1.62
@@ -497,7 +497,11 @@
 
         QTextDocument* textDoc = new QTextDocument( 0 );
         textDoc->setFormatter( new QTextFormatterBreakWords );
-        textDoc->setDefaultFont( font );        // only needed for the pointsize
+#if QT_VERSION > 304
+        textDoc->setDefaultFormat( font, Qt::black );        // only needed for the pointsize
+#else
+	textDoc->setDefaultFont( font );        // only needed for the pointsize
+#endif
         textDoc->setUnderlineLinks( true );
         textDoc->setStyleSheet( m_editor->styleSheet() );
         textDoc->setMimeSourceFactory( m_editor->mimeSourceFactory() );
