--- showimg/showimg/osd.cpp.orig	Sun Jan 29 01:47:10 2006
+++ showimg/showimg/osd.cpp	Sun Jan 29 01:57:24 2006
@@ -29,6 +29,16 @@
 //   QImage makeShadow( const QPixmap &textPixmap, const QColor &bgColor );
 //}
 
+class Grabber : public QWidget {
+public:
+    Grabber( const QRect &r, const QColor &color ) : QWidget( 0, 0 ) {
+        move( 0, 0 );
+        screen = QPixmap::grabWindow( winId(), r.x(), r.y(), r.width(), r.height() );
+        KPixmapEffect::fade( screen, 0.80, color );
+    }
+    KPixmap screen;
+};
+
 OSDWidget::OSDWidget( QWidget *parent, const char *name )
         : QWidget( parent, name, WType_TopLevel | WNoAutoErase | WStyle_Customize | WX11BypassWM | WStyle_StaysOnTop )
         , m_duration( 2000 )
@@ -51,16 +61,6 @@
 void
 OSDWidget::show() //virtual
 {
-    class Grabber : public QWidget {
-    public:
-        Grabber( const QRect &r, const QColor &color ) : QWidget( 0, 0 ) {
-            move( 0, 0 );
-            screen = QPixmap::grabWindow( winId(), r.x(), r.y(), r.width(), r.height() );
-            KPixmapEffect::fade( screen, 0.80, color );
-        }
-        KPixmap screen;
-    };
-
     if ( !isEnabled() )
         return;
 
