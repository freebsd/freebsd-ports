--- kghostview/kgv_miniwidget.cpp.orig	Fri Jan  3 05:55:05 2003
+++ kghostview/kgv_miniwidget.cpp	Mon Apr  7 17:01:29 2003
@@ -293,23 +293,22 @@ void KGVMiniWidget::openPDFFileContinue(
     }
 
     _tmpDSC->close();
-    _pdfFileName = _fileName;
-    _fileName = _tmpDSC->name();
     _format = PDF;
 
-    openPSFile();
+    openPSFile(_tmpDSC->name());
 }
 
-void KGVMiniWidget::openPSFile()
+void KGVMiniWidget::openPSFile(const QString &file)
 {
+    QString fileName = file.isEmpty() ? _fileName : file;
     kdDebug(4500) << "KGVMiniWidget::openPSFile" << endl;
     
-    FILE* fp = fopen( QFile::encodeName( _fileName ), "r");
+    FILE* fp = fopen( QFile::encodeName( fileName ), "r");
     if( fp == 0 ) 
     {
 	KMessageBox::error( _part->widget(),
 		i18n( "<qt>Error opening file <nobr><strong>%1</strong></nobr>: %2</qt>" )
-		.arg( _fileName )
+		.arg( fileName )
 		.arg( strerror( errno ) ) );
 	emit canceled( "" );
 	return;
@@ -320,9 +319,7 @@ void KGVMiniWidget::openPSFile()
 	_isFileOpen = true;    
 	scanDSC();
 	buildTOC();
-	_psWidget->setFileName( dsc()->isStructured() 
-	                            ? QString::null 
-				    : _fileName );
+	_psWidget->setFileName( _fileName, dsc()->isStructured() );
 	emit completed();
     }
 }
@@ -859,6 +856,7 @@ bool KGVMiniWidget::convertFromPDF( cons
             << "-dNOPAUSE"
             << "-dBATCH"
             << "-dSAFER"
+            << "-dPARANOIDSAFER"
             << "-sDEVICE=pswrite"
             << ( QCString("-sOutputFile=")+QFile::encodeName(saveFileName) )
             << ( QString("-dFirstPage=")+QString::number( firstPage ) )
@@ -867,7 +865,7 @@ bool KGVMiniWidget::convertFromPDF( cons
             << "save"
             << "pop"
             << "-f"
-            << QFile::encodeName(_pdfFileName);
+            << QFile::encodeName(_fileName);
 
     /*QValueList<QCString> args = process.args();
     QValueList<QCString>::Iterator it = args.begin();
@@ -1074,7 +1072,7 @@ void KGVMiniWidget::saveAs()
                           QString::null, 
                           _part->widget(), 
                           QString::null );
-    if( !KIO::NetAccess::upload( _format == PDF ? _pdfFileName : _fileName,
+    if( !KIO::NetAccess::upload( _fileName,
 				 saveURL ) )
 	; // TODO: Proper error dialog
 }
@@ -1311,10 +1309,16 @@ void Pdf2dsc::run( const QString& pdfNam
     
     _process = new KProcess;
     *_process << _ghostscriptPath
+              << "-dSAFER"
+              << "-dPARANOIDSAFER"
+              << "-dDELAYSAFER"
               << "-dNODISPLAY"
               << "-dQUIET"
               << QString( "-sPDFname=%1" ).arg( pdfName )
               << QString( "-sDSCname=%1" ).arg( dscName )
+              << "-c"
+              << "<< /PermitFileReading [ PDFname ] /PermitFileWriting [ DSCname ] /PermitFileControl [] >> setuserparams .locksafe"
+              << "-f"
               << "pdf2dsc.ps"
               << "-c"
               << "quit";
