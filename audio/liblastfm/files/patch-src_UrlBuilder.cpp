url():
  - Use https scheme to avoid 301 redirects
  - Override default QUrl::TolerantMode with QUrl::StrictMode for Qt 5.x to
    prevent overprocessing the already encoded input URL
localePath():
  - New function to return the base path of the localized website
host():
  - Just return www.last.fm since the localized hosts 301 redirect there
localize():
  - Set the path of the url instead of the host since the localized
    hosts 301 redirect to the main website with a localized path
mobilize():
  - Mobile website 301 redirects to main website, so just return the url as-is

--- src/UrlBuilder.cpp.orig	2014-10-02 14:05:46 UTC
+++ src/UrlBuilder.cpp
@@ -32,7 +32,7 @@ class lastfm::UrlBuilderPrivate (public)
 lastfm::UrlBuilder::UrlBuilder( const QString& base )
     : d( new UrlBuilderPrivate )
 {
-    d->path = '/' + base.toLatin1();
+    d->path = localePath().toLatin1() + '/' + base.toLatin1();
 }
 
 
@@ -60,10 +60,10 @@ QUrl
 lastfm::UrlBuilder::url() const
 {
     QUrl url;
-    url.setScheme( "http" );
+    url.setScheme( "https" );
     url.setHost( host() );
 #if QT_VERSION >= QT_VERSION_CHECK( 5, 0, 0 )
-    url.setPath( d->path );
+    url.setPath( d->path, QUrl::StrictMode );
 #else
     url.setEncodedPath( d->path );
 #endif
@@ -85,49 +85,50 @@ lastfm::UrlBuilder::encode( QString s )
 
 
 QString //static
-lastfm::UrlBuilder::host( const QLocale& locale )
+lastfm::UrlBuilder::localePath( const QLocale& locale )
 {
     switch (locale.language())
     {
-        case QLocale::Portuguese: return "www.lastfm.com.br";
-        case QLocale::Turkish:    return "www.lastfm.com.tr";
-        case QLocale::French:     return "www.lastfm.fr";
-        case QLocale::Italian:    return "www.lastfm.it";
-        case QLocale::German:     return "www.lastfm.de";
-        case QLocale::Spanish:    return "www.lastfm.es";
-        case QLocale::Polish:     return "www.lastfm.pl";
-        case QLocale::Russian:    return "www.lastfm.ru";
-        case QLocale::Japanese:   return "www.lastfm.jp";
-        case QLocale::Swedish:    return "www.lastfm.se";
-        case QLocale::Chinese:    return "cn.last.fm";
-        default:                  return "www.last.fm";
+        case QLocale::Chinese:    return "/zh";
+        case QLocale::French:     return "/fr";
+        case QLocale::German:     return "/de";
+        case QLocale::Italian:    return "/it";
+        case QLocale::Japanese:   return "/ja";
+        case QLocale::Polish:     return "/pl";
+        case QLocale::Portuguese: return "/pt";
+        case QLocale::Russian:    return "/ru";
+        case QLocale::Spanish:    return "/es";
+        case QLocale::Swedish:    return "/sv";
+        case QLocale::Turkish:    return "/tr";
+        default:                  return "";
     }
 }
 
 
+QString //static
+lastfm::UrlBuilder::host( const QLocale& locale )
+{
+    return "www.last.fm";
+}
+
+
 bool // static
 lastfm::UrlBuilder::isHost( const QUrl& url )
 {
-    QStringList hosts = QStringList() << "www.lastfm.com.br"
-                    <<  "www.lastfm.com.tr"
-                    << "www.lastfm.fr"
-                    << "www.lastfm.it"
-                    << "www.lastfm.de"
-                    << "www.lastfm.es"
-                    << "www.lastfm.pl"
-                    << "www.lastfm.ru"
-                    << "www.lastfm.jp"
-                    << "www.lastfm.se"
-                    << "cn.last.fm"
-                    << "www.last.fm";
+    QStringList hosts = QStringList() << "www.last.fm";
 
     return hosts.contains( url.host() );
 }
 
+
 QUrl //static
 lastfm::UrlBuilder::localize( QUrl url)
 {
-    url.setHost( url.host().replace( QRegExp("^(www.)?last.fm"), host() ) );
+#if QT_VERSION >= QT_VERSION_CHECK( 5, 0, 0 )
+    url.setPath( url.path().prepend( localePath() ), QUrl::DecodedMode );
+#else
+    url.setPath( url.path().prepend( localePath() ) );
+#endif
     return url;
 }
 
@@ -135,7 +136,6 @@ lastfm::UrlBuilder::localize( QUrl url)
 QUrl //static
 lastfm::UrlBuilder::mobilize( QUrl url )
 {
-    url.setHost( url.host().replace( QRegExp("^(www.)?last"), "m.last" ) );
     return url;
 }
 
