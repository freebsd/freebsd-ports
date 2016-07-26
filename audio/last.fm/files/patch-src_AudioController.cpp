--- src/AudioController.cpp.orig	2016-07-26 15:06:09 UTC
+++ src/AudioController.cpp
@@ -168,13 +168,7 @@ AudioControllerThread::loadPlugins()
 
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
