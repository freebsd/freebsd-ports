mobilize():
  - Mobile website 301 redirects to main website, so just return the url as-is

--- src/UrlBuilder.cpp.orig	2024-11-24 17:34:23 UTC
+++ src/UrlBuilder.cpp
@@ -118,7 +118,6 @@ lastfm::UrlBuilder::mobilize( QUrl url )
 QUrl //static
 lastfm::UrlBuilder::mobilize( QUrl url )
 {
-    url.setHost( url.host().replace( QRegularExpression("^(www.)?last"), "m.last" ) );
     return url;
 }
 
