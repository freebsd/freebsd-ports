--- kontact/src/main.cpp
+++ kontact/src/main.cpp
@@ -199,9 +199,11 @@ int main( int argc, char **argv )
 
   KontactApp app;
 
+#if !KDE_IS_VERSION(4,6,0)
   // KDE 4.4: do akonadi startup before creating any window, since creating
   // the window loads kmail. In 4.5 we'll do this startup async instead.
   Akonadi::Control::start( 0 );
+#endif
 
   // Qt doesn't treat the system tray as a window, and therefore Qt would quit
   // the event loop when an error message is clicked away while Kontact is in the
