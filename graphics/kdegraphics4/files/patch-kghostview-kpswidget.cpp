--- kghostview/kpswidget.cpp.orig	Sun Sep 15 23:12:40 2002
+++ kghostview/kpswidget.cpp	Mon Apr  7 17:04:00 2003
@@ -309,10 +309,11 @@ void KPSWidget::setGhostscriptArguments(
     }
 }
 
-void KPSWidget::setFileName( const QString& fileName )
+void KPSWidget::setFileName( const QString& fileName, bool usePipe )
 {
-    if( _fileName != fileName )
+    if(( _fileName != fileName ) || (_usePipe != usePipe))
     {
+        _usePipe = usePipe;
 	_fileName = fileName;
 	stopInterpreter();
 	_ghostscriptDirty = true;
@@ -508,8 +509,11 @@ void KPSWidget::startInterpreter()
     for( ; it != _ghostscriptArguments.end(); ++it )
 	*_process << (*it);
     
-    if( _fileName.isEmpty() )
-	*_process << "-";
+    if( _usePipe )
+        *_process <<
+        // The following two lines are their to ensure that we are allowed to read _fileName
+        "-dDELAYSAFER" << "-sInputFile="+_fileName << "-c" <<
+        "<< /PermitFileReading [ InputFile ] /PermitFileWriting [] /PermitFileControl [] >> setuserparams .locksafe";
     else
 	*_process << _fileName << "-c" << "quit";
 
@@ -527,7 +531,7 @@ void KPSWidget::startInterpreter()
     // Finally fire up the interpreter.
     kdDebug(4500) << "KPSWidget: starting interpreter" << endl;
     if( _process->start( KProcess::NotifyOnExit, 
-              _fileName.isEmpty() ? KProcess::All : KProcess::AllOutput ) ) 
+              _usePipe ? KProcess::All : KProcess::AllOutput ) ) 
     {
 	_interpreterBusy = true;
 	setCursor( waitCursor );
@@ -648,7 +652,7 @@ void KPSWidget::readSettings()
     if( !intConfig->platformFonts() )
 	arguments << "-dNOPLATFONTS";
     
-    arguments << "-dNOPAUSE" << "-dQUIET" << "-dSAFER";
+    arguments << "-dNOPAUSE" << "-dQUIET" << "-dSAFER" << "-dPARANOIDSAFER";
 
     setGhostscriptArguments( arguments );
 
