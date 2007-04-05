diff -Naur kbibtex-0.1.5_orig/src/settings.cpp kbibtex-0.1.5/src/settings.cpp
--- src/settings.cpp	2006-10-03 21:14:45.000000000 +0200
+++ src/settings.cpp	2007-02-27 13:20:13.000000000 +0100
@@ -170,7 +170,7 @@
 
         config->setGroup( "SearchURLs" );
         int i = 1;
-        for ( QValueList<SearchURL*>::ConstIterator it = searchURLs.begin(); it != searchURLs.end(); ++it )
+        for ( QValueList<SearchURL*>::ConstIterator it = searchURLs.begin(); it != searchURLs.end(); ++it, ++i )
         {
             config->writeEntry( QString( "SearchURLDescription%1" ).arg( i ), ( *it ) ->description );
             config->writeEntry( QString( "SearchURL%1" ).arg( i ), ( *it ) ->url );
