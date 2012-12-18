--- ./src/cmds/cmds.cpp.orig	2012-12-02 18:48:47.000000000 -0500
+++ ./src/cmds/cmds.cpp	2012-12-02 18:54:38.000000000 -0500
@@ -89,9 +89,9 @@
 
 
 	QPalette newPalette = QPalette();
-	newPalette.setColor(QPalette::Background, QColor::QColor(170,170,255));
-	newPalette.setColor(QPalette::Foreground, QColor::QColor(0,0,0));
-	newPalette.setColor(QPalette::Base, QColor::QColor(170,170,255));
+	newPalette.setColor(QPalette::Background, QColor(170,170,255));
+	newPalette.setColor(QPalette::Foreground, QColor(0,0,0));
+	newPalette.setColor(QPalette::Base, QColor(170,170,255));
 
 	setPalette(newPalette);
 	
