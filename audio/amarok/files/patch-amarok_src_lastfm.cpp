
$FreeBSD$

--- amarok/src/lastfm.cpp.orig
+++ amarok/src/lastfm.cpp
@@ -729,7 +729,7 @@
 
     QCString md5pass = KMD5( KMD5( m_password.utf8() ).hexDigest() + currentTime ).hexDigest();
 
-    QString token = QString( "user=%1&auth=%2&nonce=%3recipient=%4" )
+    token = QString( "user=%1&auth=%2&nonce=%3recipient=%4" )
                        .arg( QString( QUrl( currentUsername() ).encodedPathAndQuery() ) )
                        .arg( QString( QUrl( md5pass ).encodedPathAndQuery() ) )
                        .arg( QString( QUrl( challenge ).encodedPathAndQuery() ) )
