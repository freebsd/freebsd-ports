commit 1ce93440f9dbfcd01a3f4c11119f120e82a7dfb2
Author: Christophe Giboudeaux <cgiboudeaux@gmx.com>
Date:   Sat Jan 21 18:29:43 2012 +0100

    Build with Clang.

diff --git a/server/src/nepomuk/queryserviceclient.h b/server/src/nepomuk/queryserviceclient.h
index a0e7517..3c551a0 100644
--- ./server/src/nepomuk/queryserviceclient.h
+++ ./server/src/nepomuk/queryserviceclient.h
@@ -78,7 +78,7 @@ namespace Nepomuk {
              *
              * \sa QueryParser
              */
-            bool query( const QString& query, const QHash<QString, QString> &encodedRps = QHash<QString, QString>() );
+            bool query(const QString& query, const QHash<QString, QString> &encodedRps = ( QHash<QString, QString>() ) );
 
             /**
              * Start a query using the Nepomuk user query language.
@@ -96,7 +96,7 @@ namespace Nepomuk {
              * 
              * \sa query(const QString&), close()
              */
-            bool blockingQuery( const QString& query, const QHash<QString, QString> &encodedRps = QHash<QString, QString>() );
+            bool blockingQuery( const QString& query, const QHash<QString, QString> &encodedRps = ( QHash<QString, QString>() ) );
 
             /**
              * Close the client, thus stop to monitor the query
