--- FileDialog.cpp.orig	Sun Feb 23 01:23:20 2003
+++ FileDialog.cpp	Sun Feb 23 01:25:40 2003
@@ -199,8 +199,6 @@
 	int	wHeight = 25;
 	int	wWidth = 90;
 	setFrameStyle(QFrame::Panel | QFrame::Sunken);
-	setFontPropagation(NoChildren);
-	setPalettePropagation(NoChildren);
 	
 	resizeCombo = new QComboBox(this);
 	resizeCombo->setFixedSize(wWidth, wHeight);
