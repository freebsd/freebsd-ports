--- ./svx/source/items/clipfmtitem.cxx.orig	2012-07-27 08:37:04.000000000 -0400
+++ ./svx/source/items/clipfmtitem.cxx	2012-08-14 18:47:08.000000000 -0400
@@ -133,7 +133,7 @@
     if( nPos > pImpl->aFmtNms.size() )
         nPos = pImpl->aFmtNms.size();
 
-    pImpl->aFmtNms.insert(pImpl->aFmtNms.begin() + nPos, NULL);
+    pImpl->aFmtNms.insert(pImpl->aFmtNms.begin() + nPos, 0);
     pImpl->aFmtIds.insert( pImpl->aFmtIds.begin()+nPos, nId );
 }
 
