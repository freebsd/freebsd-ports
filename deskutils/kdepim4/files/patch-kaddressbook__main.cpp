--- kaddressbook/main.cpp
+++ kaddressbook/main.cpp
@@ -49,11 +49,13 @@ int main( int argc, char **argv )
   MainWindow *window = new MainWindow;
   window->show();
 
+#if !KDE_IS_VERSION(4,6,0)
   if ( !Akonadi::Control::start( window ) ) {
     //TODO: add message box after string freeze
     kWarning() << "Unable to start Akonadi server, exit application";
     return 1;
   }
+#endif
 
   return app.exec();
 }
