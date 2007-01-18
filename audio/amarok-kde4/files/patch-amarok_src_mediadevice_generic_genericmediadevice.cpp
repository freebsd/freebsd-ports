
$FreeBSD$

--- amarok/src/mediadevice/generic/genericmediadevice.cpp.orig
+++ amarok/src/mediadevice/generic/genericmediadevice.cpp
@@ -415,7 +415,13 @@
         if( m_medium.mountPoint() == (*mountiter)->mountPoint() )
             m_medium.setFsType( (*mountiter)->mountType() );
     }
-    m_actuallyVfat = m_medium.fsType() == "vfat" ? true : false;
+    m_actuallyVfat = m_medium.fsType() == 
+#ifdef __FreeBSD__
+"msdosfs"
+#else
+"vfat"
+#endif
+ ? true : false;
     m_connected = true;
     m_transferDir = m_medium.mountPoint();
     m_initialFile = new GenericMediaFile( 0, m_medium.mountPoint(), this );
@@ -457,7 +463,7 @@
     debug() << "Renaming: " << src << " to: " << dst << endl;
 
     //do we want a progress dialog?  If so, set last false to true
-    if( KIO::NetAccess::file_move( KURL::fromPathOrURL(src), KURL::fromPathOrURL(dst), -1, false, false, false ) )
+    if( KIO::NetAccess::file_move( KURL::fromPathOrURL(src), KURL::fromPathOrURL(dst), -1, false, false, 0 ) )
     {
         m_mfm.erase( m_mim[item]->getFullName() );
         m_mim[item]->setNamesFromBase( item->text(0) );
