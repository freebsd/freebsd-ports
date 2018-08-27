contains() returns a bool, clang7 complains

--- lib/dictquery.cpp.orig	2018-08-27 21:16:58 UTC
+++ lib/dictquery.cpp
@@ -459,7 +459,7 @@ QString DictQuery::operator[] ( const QS
 
 bool DictQuery::hasProperty( const QString &key ) const
 {
-  return d->entryOrder.contains( key ) > 0;
+  return d->entryOrder.contains( key );
 }
 
 //TODO: Add i18n handling and alternate versions of property names
