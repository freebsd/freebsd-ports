--- src/fileimporter.h.orig	Mon Mar 26 20:15:05 2007
+++ src/fileimporter.h	Mon Mar 26 20:15:33 2007
@@ -39,7 +39,7 @@
         ~FileImporter();
 
         File* load ( const QString& text );
-        virtual File* load( QIODevice *iodevice ) = NULL;
+        virtual File* load( QIODevice *iodevice ) = 0;
 
         static bool guessCanDecode( const QString & ) { return FALSE; };
 
