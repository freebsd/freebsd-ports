--- ark/tar.cpp.orig	Thu Apr 15 21:48:14 2004
+++ ark/tar.cpp	Thu Apr 15 21:49:21 2004
@@ -81,7 +81,7 @@
 
     m_fileMimeType = _openAsMimeType;
     if ( m_fileMimeType.isNull() )
-        m_fileMimeType = KMimeType::findByFileContent( _filename )->name();
+        m_fileMimeType = KMimeType::findByPath( _filename )->name();
 
     kdDebug(1601) << "TarArch::TarArch:  mimetype is " << m_fileMimeType << endl;
 
