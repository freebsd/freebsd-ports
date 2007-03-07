--- amarok/src/mediadevice/generic/genericmediadevice.cpp.orig	Mon Feb 12 23:01:20 2007
+++ amarok/src/mediadevice/generic/genericmediadevice.cpp	Mon Feb 12 23:01:29 2007
@@ -418,13 +418,7 @@
         if( m_medium.mountPoint() == (*mountiter)->mountPoint() )
             m_medium.setFsType( (*mountiter)->mountType() );
     }
-    m_actuallyVfat = m_medium.fsType() == 
-#ifdef __FreeBSD__
-        "msdosfs"
-#else
-        "vfat" 
-#endif
-        ? true : false;
+    m_actuallyVfat = (m_medium.fsType() == "vfat" || m_medium.fsType() == "msdosfs") ? true : false;
     m_connected = true;
     m_transferDir = m_medium.mountPoint();
     m_initialFile = new GenericMediaFile( 0, m_medium.mountPoint(), this );

