--- kmail/main.cpp
+++ kmail/main.cpp
@@ -145,12 +145,14 @@ int main(int argc, char *argv[])
   app.setEventLoopReached();
   app.delayedInstanceCreation();
 
+#if !KDE_IS_VERSION(4,6,0)
   // Start Akonadi
   if ( !Akonadi::Control::start( kmkernel->getKMMainWidget() ) ) {
     //TODO: add message box after string freeze
     kWarning() << "Unable to start Akonadi server, exit application";
     return 1;
   }
+#endif
 
   // Go!
   int ret = qApp->exec();
