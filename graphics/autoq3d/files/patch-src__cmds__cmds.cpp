--- src/cmds/cmds.cpp.orig	2016-03-24 23:43:09 UTC
+++ src/cmds/cmds.cpp
@@ -89,9 +89,9 @@ cmds::cmds( QWidget* parent)
 
 
 	QPalette newPalette = QPalette();
-	newPalette.setColor(QPalette::Background, QColor::QColor(170,170,255));
-	newPalette.setColor(QPalette::Foreground, QColor::QColor(0,0,0));
-	newPalette.setColor(QPalette::Base, QColor::QColor(170,170,255));
+	newPalette.setColor(QPalette::Background, QColor(170,170,255));
+	newPalette.setColor(QPalette::Foreground, QColor(0,0,0));
+	newPalette.setColor(QPalette::Base, QColor(170,170,255));
 
 	setPalette(newPalette);
 	
