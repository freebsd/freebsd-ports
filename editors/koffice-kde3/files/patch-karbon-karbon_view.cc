--- ./karbon/karbon_view.cc.orig	Sat Aug 31 07:12:55 2002
+++ ./karbon/karbon_view.cc	Sun Nov 17 06:31:40 2002
@@ -1086,7 +1086,7 @@
     m_joinStyle->addState( new QPixmap( DesktopIcon( "join_miter" ) ) );
     m_joinStyle->addState( new QPixmap( DesktopIcon( "join_round" ) ) );
     m_joinStyle->setState( 0 );
-#if KDE_VERSION >= 305
+#if KDE_VERSION >= 306
 	new KWidgetAction( m_joinStyle, i18n("Set Join Style"), 0, this, SLOT( slotJoinStyleClicked() ), actionCollection(), "setJoinStyle" );
 #endif
 	connect( m_joinStyle, SIGNAL(clicked()), this, SLOT(slotJoinStyleClicked()) );
@@ -1097,7 +1097,7 @@
     m_capStyle->addState( new QPixmap( DesktopIcon( "cap_square" ) ) );
     m_capStyle->addState( new QPixmap( DesktopIcon( "cap_round" ) ) );
     m_capStyle->setState( 0 );
-#if KDE_VERSION >= 305
+#if KDE_VERSION >= 306
 	new KWidgetAction( m_capStyle, i18n("Set Cap Style"), 0, this, SLOT( slotCapStyleClicked() ), actionCollection(), "setCapStyle" );
 #endif
 	connect( m_capStyle, SIGNAL(clicked()), this, SLOT(slotCapStyleClicked()) );
@@ -1109,7 +1109,7 @@
 				this, SLOT( selectionChanged() ) );
 		connect( m_strokeFillPreview, SIGNAL( fillChanged( const VFill & ) ),
 				this, SLOT( selectionChanged() ) );
-#if KDE_VERSION >= 305
+#if KDE_VERSION >= 306
 		//new KWidgetAction( m_strokeFillPreview, i18n(""), 0, this, SLOT( ), actionCollection(), "preview" );
 #endif
 		mainWindow()->toolBar( "Toolbox" )->insertWidget( 10, 30, m_strokeFillPreview );
