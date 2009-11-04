--- src/AudioController.cpp.orig	2007-12-18 15:18:20.000000000 +0100
+++ src/AudioController.cpp	2009-11-04 19:22:00.000000000 +0100
@@ -168,13 +168,7 @@
 
     m_transcode->setBufferCapacity( kDecodedBufferMinSize );
 
-    #ifdef WIN32
         m_output = qobject_cast<OutputInterface*>( loadPlugin( "rtaudioplayback" ) );
-    #elif defined LINUX
-        m_output = qobject_cast<OutputInterface*>( loadPlugin( "output_alsa" ) );
-    #else
-        m_output = qobject_cast<OutputInterface*>( loadPlugin( "output_portaudio" ) );
-    #endif
 
     if ( m_output == 0 )
         return false;
