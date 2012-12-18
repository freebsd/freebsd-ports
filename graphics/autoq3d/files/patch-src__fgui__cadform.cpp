--- ./src/fgui/cadform.cpp.orig	2012-12-02 18:48:47.000000000 -0500
+++ ./src/fgui/cadform.cpp	2012-12-02 18:51:14.000000000 -0500
@@ -475,9 +475,9 @@
 
 
 	QPalette newPalette = palette();
-	newPalette.setColor(QPalette::Background, QColor::QColor(170,170,255));
-	newPalette.setColor(QPalette::Foreground, QColor::QColor(0,0,0));
-	newPalette.setColor(QPalette::Base, QColor::QColor(170,170,255));
+	newPalette.setColor(QPalette::Background, QColor(170,170,255));
+	newPalette.setColor(QPalette::Foreground, QColor(0,0,0));
+	newPalette.setColor(QPalette::Base, QColor(170,170,255));
 
 
 
@@ -800,7 +800,7 @@
 	w->GLThisArea->cscalari=hcmd->cscalari;
 	w->GLThisArea->View=View;
 
-	w->setWindowTitle(QString::QString(tr("ViewPort-%1")).arg(numDoc++));w->setWindowIcon( QPixmap(ProgramPath+"images/document.png") );
+	w->setWindowTitle(QString(tr("ViewPort-%1")).arg(numDoc++));w->setWindowIcon( QPixmap(ProgramPath+"images/document.png") );
 	w->show();
 	QWidgetList windoL=ws->windowList(QWorkspace::CreationOrder);
 	if ( windoL.count()==1){
