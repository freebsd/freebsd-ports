--- lib/kotext/KoParagDia.cpp	2006/04/02 23:37:38	525830
+++ lib/kotext/KoParagDia.cpp	2006/04/06 19:39:40	527078
@@ -772,6 +772,20 @@
 /******************************************************************/
 /* Class: KoStylePreview. Previewing text with style ;)           */
 /******************************************************************/
+class MyFlow : public KoTextFlow {
+    public:
+        MyFlow(QWidget *parent, KoTextZoomHandler *zoom) {
+            m_parent = parent;
+            m_zoomHandler = zoom;
+        }
+        int availableHeight() const {
+            return m_zoomHandler->pixelToLayoutUnitY(m_parent->height());
+        }
+    private:
+        QWidget *m_parent;
+        KoTextZoomHandler *m_zoomHandler;
+};
+
 KoStylePreview::KoStylePreview( const QString& title, const QString& text, QWidget* parent, const char* name )
     : QGroupBox( title, parent, name )
 {
@@ -780,20 +794,6 @@
     QFont font = KoGlobal::defaultFont();
     m_textdoc = new KoTextDocument( m_zoomHandler, new KoTextFormatCollection( font, QColor(), KGlobal::locale()->language(), false ) );
 
-    class MyFlow : public KoTextFlow {
-        public:
-            MyFlow(QWidget *parent, KoTextZoomHandler *zoom) {
-                m_parent = parent;
-                m_zoomHandler = zoom;
-            }
-            int availableHeight() const {
-                return m_zoomHandler->pixelToLayoutUnitY(m_parent->height());
-            }
-        private:
-            QWidget *m_parent;
-            KoTextZoomHandler *m_zoomHandler;
-    };
-
     m_textdoc->setFlow( new MyFlow(this, m_zoomHandler) );
     //m_textdoc->setWidth( KoTextZoomHandler::ptToLayoutUnitPt( 1000 ) );
     KoTextParag * parag = m_textdoc->firstParag();
