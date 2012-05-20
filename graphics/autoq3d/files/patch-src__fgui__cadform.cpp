--- src/fgui/cadform.cpp~	2012-05-19 22:45:11.000000000 -0300
+++ src/fgui/cadform.cpp	2012-05-19 22:46:08.000000000 -0300
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
