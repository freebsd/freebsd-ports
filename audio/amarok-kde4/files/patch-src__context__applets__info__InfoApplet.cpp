diff --git a/src/context/applets/info/InfoApplet.cpp b/src/context/applets/info/InfoApplet.cpp
index 166da4c..e415e98 100644
--- ./src/context/applets/info/InfoApplet.cpp
+++ ./src/context/applets/info/InfoApplet.cpp
@@ -40,18 +40,30 @@ QString InfoApplet::s_defaultHtml = "<html>"
 
 InfoApplet::InfoApplet( QObject* parent, const QVariantList& args )
     : Context::Applet( parent, args )
+    , m_webView( 0 )
     , m_initialized( false )
     , m_currentPlaylist( 0 )
+   
 {
     setHasConfigurationInterface( false );
     setBackgroundHints( Plasma::Applet::NoBackground );
+}
+
+InfoApplet::~InfoApplet()
+{
+    delete m_webView;
+}
+
+
+void  InfoApplet::init()
+{
 
     dataEngine( "amarok-info" )->connectSource( "info", this );
 
     m_webView = new AmarokWebView( this );
 
     resize( 500, -1 );
-    
+
     QPalette p = m_webView->palette();
     p.setColor( QPalette::Dark, QColor( 255, 255, 255, 0)  );
     p.setColor( QPalette::Window, QColor( 255, 255, 255, 0)  );
@@ -62,11 +74,6 @@ InfoApplet::InfoApplet( QObject* parent, const QVariantList& args )
     constraintsEvent();
 }
 
-InfoApplet::~InfoApplet()
-{
-    delete m_webView;
-}
-
 void InfoApplet::constraintsEvent( Plasma::Constraints constraints )
 {
     Q_UNUSED( constraints )
