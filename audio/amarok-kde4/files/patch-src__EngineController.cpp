diff --git a/src/EngineController.cpp b/src/EngineController.cpp
index 521e570..3d57dad 100644
--- ./src/EngineController.cpp
+++ ./src/EngineController.cpp
@@ -172,10 +172,14 @@
     connect( m_controller, SIGNAL( titleChanged( int ) ), SLOT( slotTitleChanged( int ) ) );
 
 
+    // Gapless Playback is temporarily disabled. Reason: Trying to find a bug in this code that makes
+    // the EngineController stop after each track, with all Phonon backends except the xine backend.
+#if 0
     if( AmarokConfig::trackDelayLength() > -1 )
         m_media->setTransitionTime( AmarokConfig::trackDelayLength() ); // Also Handles gapless.
     else if( AmarokConfig::crossfadeLength() > 0 )  // TODO: Handle the possible options on when to crossfade.. the values are not documented anywhere however
         m_media->setTransitionTime( -AmarokConfig::crossfadeLength() );
+#endif
 }
 
 
