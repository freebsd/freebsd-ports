--- src/AudioController.cpp.orig	Sat Jul 14 09:50:13 2007
+++ src/AudioController.cpp	Sat Jul 14 09:50:28 2007
@@ -160,13 +160,7 @@
     }
     m_transcode->setBufferCapacity( kDecodedBufferMinSize );
     
-    #ifdef WIN32
         m_output = qobject_cast<OutputInterface*>( loadPlugin( "rtaudioplayback" ) );
-    #elif defined LINUX
-        m_output = qobject_cast<OutputInterface*>( loadPlugin( "output_alsa" ) );
-    #else
-        m_output = qobject_cast<OutputInterface*>( loadPlugin( "output_portaudio" ) );
-    #endif
 
     if ( m_output == 0 )
     {
