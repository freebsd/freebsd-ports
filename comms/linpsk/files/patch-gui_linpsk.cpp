Fix bogus pointer comparison.

--- gui/linpsk.cpp.orig	2017-01-22 12:03:55 UTC
+++ gui/linpsk.cpp
@@ -387,7 +387,7 @@ void LinPSK::startTx()
       Info = "BPSK";
       break;
   }
-  if ( Sound <= NULL ) // Only create Sound Device once for output
+  if ( !Sound ) // Only create Sound Device once for output
   {
     if ( settings.DemoMode )
     {
@@ -401,7 +401,7 @@ void LinPSK::startTx()
       Sound = new CSound ( settings.serial );
     connect ( Sound, SIGNAL ( samplesAvailable() ), this, SLOT ( process_txdata() ) );
   }
-  if ( Sound <= NULL )
+  if ( !Sound )
   {
     QMessageBox::critical ( 0, " Programm Error! LinPsk", "Could not create Sound Device for Output" );
     TxDisplay->TxFunctions->setStatus ( ON );
