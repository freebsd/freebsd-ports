
$FreeBSD$

--- amarok/src/mediadevice/generic/genericmediadevice.cpp.orig
+++ amarok/src/mediadevice/generic/genericmediadevice.cpp
@@ -406,7 +406,7 @@
     debug() << "Renaming: " << src << " to: " << dst << endl;
 
     //do we want a progress dialog?  If so, set last false to true
-    if( KIO::NetAccess::file_move( KURL::fromPathOrURL(src), KURL::fromPathOrURL(dst), -1, false, false, false ) )
+    if( KIO::NetAccess::file_move( KURL::fromPathOrURL(src), KURL::fromPathOrURL(dst), -1, false, false, 0 ) )
     {
         m_mfm.erase( m_mim[item]->getFullName() );
         m_mim[item]->setNamesFromBase( item->text(0) );
