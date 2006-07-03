--- amarok/src/statusbar/selectLabel.h.orig	Sat Jul  1 20:30:36 2006
+++ amarok/src/statusbar/selectLabel.h	Sat Jul  1 20:31:51 2006
@@ -126,7 +126,7 @@
             if( !isEnabled() )
                 tip += i18n("&nbsp;<br>&nbsp;<i>Disabled</i>");
             else if( AmarokConfig::favorTracks() &&
-                     m_action == amaroK::actionCollection()->action( "random_mode" ) ) //hack?
+                     m_action == static_cast<amaroK::SelectAction*>( amaroK::actionCollection()->action( "random_mode" ) ) ) //hack?
             {
                 KSelectAction *a = static_cast<KSelectAction*>( amaroK::actionCollection()->action( "favor_tracks" ) );
                 tip += QString("<br><br>") + i18n("%1: %2")
