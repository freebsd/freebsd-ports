--- knode/knfiltermanager.cpp.orig	2018-09-01 19:13:40 UTC
+++ knode/knfiltermanager.cpp
@@ -201,7 +201,7 @@ void KNFilterManager::addFilter(KNArticleFilter *f)
     foreach ( KNArticleFilter *filter, mFilterList )
       activeFilters << filter->id();
     int newId = 1;
-    while ( activeFilters.contains( newId ) > 0 )
+    while ( bool(activeFilters.contains( newId )) )
       newId++;
     f->setId( newId );
   }
