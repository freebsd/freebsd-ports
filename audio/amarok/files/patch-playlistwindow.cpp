--- amarok/src/playlistwindow.cpp.orig	Thu Jun 17 15:12:24 2004
+++ amarok/src/playlistwindow.cpp	Thu Jun 17 15:13:34 2004
@@ -465,8 +465,11 @@
     const KWin::WindowInfo info = KWin::windowInfo( winId() );
     const uint desktop = KWin::currentDesktop();
     const bool isOnThisDesktop = info.isOnDesktop( desktop );
+#if KDE_IS_VERSION(3,2,1)
     const bool isShaded = info.hasState( NET::Shaded );
-
+#else
+    const bool isShaded = false;
+#endif
 
     if( isShaded )
     {
