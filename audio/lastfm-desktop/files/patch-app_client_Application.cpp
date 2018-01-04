--- app/client/Application.cpp.orig	2017-12-21 08:34:38 UTC
+++ app/client/Application.cpp
@@ -430,7 +430,7 @@ Application::showAs( bool showAs )
 void
 Application::setRaiseHotKey( Qt::KeyboardModifiers mods, int key )
 {
-    if( m_raiseHotKeyId >= 0 )
+    if( m_raiseHotKeyId >= (void *)0 )
         unInstallHotKey( m_raiseHotKeyId );
 
     m_raiseHotKeyId = installHotKey( mods, key, m_toggle_window_action, SLOT(trigger()));
