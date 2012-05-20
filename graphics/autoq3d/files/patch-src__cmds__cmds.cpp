--- src/cmds/cmds.cpp~	2012-05-19 22:44:14.000000000 -0300
+++ src/cmds/cmds.cpp	2012-05-19 22:44:25.000000000 -0300
@@ -89,9 +89,9 @@
 
 
 	QPalette newPalette = QPalette();
-	newPalette.setColor(QPalette::Background, QColor::QColor(170,170,255));
-	newPalette.setColor(QPalette::Foreground, QColor::QColor(0,0,0));
-	newPalette.setColor(QPalette::Base, QColor::QColor(170,170,255));
+	newPalette.setColor(QPalette::Background, QColor(170,170,255));
+	newPalette.setColor(QPalette::Foreground, QColor(0,0,0));
+	newPalette.setColor(QPalette::Base, QColor(170,170,255));
 
 	setPalette(newPalette);
 	
