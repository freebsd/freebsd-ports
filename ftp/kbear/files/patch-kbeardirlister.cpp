--- kbear/parts/filesyspart/kbeardirlister.cpp	Thu Jun 20 18:51:32 2002
+++ kbear/parts/filesyspart/kbeardirlister.cpp	Wed Jul 17 10:18:18 2002
@@ -30,16 +30,17 @@
 #include <kdirlister.h>
 #include <kapplication.h>
 #include <kdirwatch.h>
 #include <kconfig.h>
 #include <kio/slave.h>
 #include <kio/scheduler.h>
 #include <kparts/part.h>
 #include <kparts/componentfactory.h>
+#include <ktrader.h>
 #include <kdebug.h>
 //////////////////////////////////////////////////////////////////////
 // Application specific include files
 #include "kbeardirlister.h"
 #include "../../base/kbearlistjob.h"
 #include "../../base/kbeardeletejob.h"
 #include "../../base/kbearconnectionmanager.h"
 
@@ -98,34 +99,40 @@
 }
 //-----------------------------------------------
 KParts::ReadOnlyPart* KBearDirLister::getPreviewPartInternal( const QString& mime ) {
 	kdDebug()<<"KBearDirLister::getPreviewPartInternal() mime in="<<mime<<endl;
 	// first we need to find out if user want ReadOnly, ReadWrite or want to be asked
 	QString oldGroup = kapp->config()->group();
 	kapp->config()->setGroup("General");
 	unsigned int viewMode = kapp->config()->readUnsignedNumEntry( "Preview Mode", 0 );
+
 	if( viewMode == 2 ) { // Ask
 		int ret = KMessageBox::questionYesNoCancel( 0L, i18n( "Do you want to open the file in read only mode or in read/write mode ?"),
 													i18n("Select view mode..."), KGuiItem(i18n("Read only")), KGuiItem(i18n("Read/write")) );
 		if( ret == KMessageBox::Cancel )
 			m_partViewer = (KParts::ReadOnlyPart*)1;	
 		else if( ret == KMessageBox::No )
 			viewMode = 1; // ReadWrite						
 	}
+
+	QObject* obj = 0L;
 	if( viewMode == 1 ) { // ReadWrite
-		m_partViewer = KParts::ComponentFactory::
-							createPartInstanceFromQuery<KParts::ReadWritePart>
-							( mime, QString::null, m_partViewerWidget, "PreviewWidget", m_partViewerWidget, "PreviewPart" );
-	}
-	if( ! m_partViewer ) { // ReadOnly
-		m_partViewer = KParts::ComponentFactory::
-							createPartInstanceFromQuery<KParts::ReadOnlyPart>
-							( mime, QString::null, m_partViewerWidget, "PreviewWidget", m_partViewerWidget, "PreviewPart" );
+		obj = KParts::ComponentFactory::
+							createInstanceFromQuery<KParts::ReadWritePart>
+							( mime, QString::null, m_partViewerWidget, "PreviewPart" );
+	}
+	if( ! obj ) { // ReadOnly
+		obj = KParts::ComponentFactory::
+							createInstanceFromQuery<KParts::ReadOnlyPart>
+							( mime, QString::null, m_partViewerWidget, "PreviewPart" );
 	}
+	if( obj )
+		m_partViewer = dynamic_cast<KParts::ReadOnlyPart*>( obj );
+
 	kapp->config()->setGroup( oldGroup );
 	return m_partViewer;
 }
 //-----------------------------------------------
 KParts::ReadOnlyPart* KBearDirLister::getPreviewPart( const KURL& url, QWidget* parent ) {
 	kdDebug()<<"KBearDirLister::getPreviewPart url="<<url.prettyURL()<<endl;
 	m_previewURL = url;
 	m_mime = QString::null;
@@ -173,18 +180,18 @@
 		KMessageBox::detailedError( 0L, list[1], list[2], list[0] );
 	}
 	m_mime = "error";
 }
 //-----------------------------------------------
 void KBearDirLister::slotMimeType( KIO::Job*, const QString& mime ) {
 	kdDebug()<<"KBearDirLister::slotMimeType() mime="<<mime<<endl;
 	m_partViewer = getPreviewPartInternal( mime );
-	if( (int)m_partViewer > 1 ) {
-	connectionManager->putOnHold( (unsigned long)this );
+	if( m_partViewer && (int)m_partViewer > 1 ) {
+		connectionManager->putOnHold( (unsigned long)this );
 		connect( m_slave, SIGNAL( infoMessage( const QString& ) ),
 					this, SIGNAL( infoMessage( const QString& ) ) );
 	}
 	m_mime = mime;
 }
 //-----------------------------------------------
 void KBearDirLister::slotDisconnectSlaveInfo() {
 	disconnect( m_slave, SIGNAL( infoMessage( const QString& ) ),
