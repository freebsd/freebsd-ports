http://www.last.fm 301 redirects to https://www.last.fm causing test to fail

--- tests/TestUrlBuilder.h.orig	2018-03-31 12:04:00 UTC
+++ tests/TestUrlBuilder.h
@@ -81,7 +81,7 @@ private slots:
 
     void test404() /** @author <max@last.fm> */
     {
-        QCOMPARE( getResponseCode( QUrl("http://www.last.fm/404") ), 404 );
+        QCOMPARE( getResponseCode( QUrl("https://www.last.fm/404") ), 404 );
     }
 };
 
