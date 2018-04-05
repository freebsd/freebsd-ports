Add prototype for localePath() and adjust comments to reflect current
website layout

--- src/UrlBuilder.h.orig	2014-10-02 14:05:46 UTC
+++ src/UrlBuilder.h
@@ -44,9 +44,11 @@ namespace lastfm
 
         QUrl url() const;
 
-        /** www.last.fm becomes the local version, eg www.lastfm.de */
+        /** www.last.fm becomes the local version, e.g. www.last.fm/de */
         static QUrl localize( QUrl );
-        /** www.last.fm becomes m.last.fm, localisation is preserved */
+ 
+        /** DEPRECATED: Returns url as-is since the mobile website redirects
+         *  to the main website */
         static QUrl mobilize( QUrl );
 
         /** Use this to URL encode any database item (artist, track, album). It
@@ -60,7 +62,10 @@ namespace lastfm
           */
         static QByteArray encode( QString );
 
-        /** returns eg. www.lastfm.de */
+        /** returns the base path of the localized website e.g. /de */
+        static QString localePath ( const QLocale& = QLocale() );
+
+        /** returns www.last.fm */
         static QString host( const QLocale& = QLocale() );
 
         /** return true if url is a last.fm url */
