--- src/webquerypubmed.cpp	2006-10-04 21:10:15.000000000 +0200
+++ src/webquerypubmed.cpp	2007-02-27 13:44:16.000000000 +0100
@@ -206,6 +206,7 @@
         doc.setContent( buffer );
         QDomElement docElem = doc.documentElement();
         ResultParser resultParser( m_listViewResults, doc.documentElement() );
+        buffer->close();
 
         setEnabled( TRUE );
         QApplication::restoreOverrideCursor();
