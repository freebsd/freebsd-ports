Mark mobilize() as deprecated. It doesn't do anything useful.

--- src/UrlBuilder.h.orig	2024-11-24 17:34:23 UTC
+++ src/UrlBuilder.h
@@ -46,8 +46,9 @@ namespace lastfm
 
         /** www.last.fm becomes the local version, eg www.lastfm.de */
         static QUrl localize( QUrl );
-        /** www.last.fm becomes m.last.fm, localisation is preserved */
-        static QUrl mobilize( QUrl );
+        /** DEPRECATED: Returns url as-is since the mobile website 301
+         *  redirects to the main website */
+        Q_DECL_DEPRECATED static QUrl mobilize( QUrl );
 
         /** Use this to URL encode any database item (artist, track, album). It
           * internally calls UrlEncodeSpecialChars to double encode some special
