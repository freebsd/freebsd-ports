Fix bogus pointer comparison.

--- gui/crxdisplay.cpp.orig	2017-01-22 12:03:47 UTC
+++ gui/crxdisplay.cpp
@@ -98,7 +98,7 @@ bool CRxDisplay::start_process_loop()
     }
     else
       Sound = new CSound ( settings.serial );
-    if ( Sound <= NULL )
+    if ( !Sound )
       return false;
 
     connect ( Sound, SIGNAL ( samplesAvailable() ), this, SLOT ( process_rxdata() ) );
