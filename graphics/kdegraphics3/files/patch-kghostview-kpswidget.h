--- kghostview/kpswidget.h.orig	Sun Sep 15 23:12:40 2002
+++ kghostview/kpswidget.h	Mon Apr  7 17:05:04 2003
@@ -134,10 +134,11 @@ public:
     bool sendPS( FILE*, unsigned int begin, unsigned int end );
    
     /**
-     * Sets the filename of the ghostscript input. Usually we use a pipe for
-     * communication and no filename will be needed.
+     * Sets the filename of the ghostscript input. 
+     * @p usePipe indicates whether we use a pipe for
+     * communication or let ghoscript read the file itself.
      */
-    void setFileName( const QString& );
+    void setFileName( const QString&, bool usePipe );
 
     /**
      * Set the bounding box of the drawable. See my comment in the source
@@ -243,6 +244,7 @@ private:
     QString     _ghostscriptPath;
     QStringList _ghostscriptArguments;
     QString     _fileName;
+    bool        _usePipe;
 
     /**
      * Flag set when one of the properties _ghostscriptPath, 
