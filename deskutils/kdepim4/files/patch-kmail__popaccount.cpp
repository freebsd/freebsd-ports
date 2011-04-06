--- kmail/popaccount.cpp
+++ kmail/popaccount.cpp
@@ -959,11 +959,13 @@ void PopAccount::slotData( KIO::Job* job, const QByteArray &data)
            .subs( numBytesToRead/1024 ).subs( mLogin ).subs( mHost )
            .toString();
       }
-      mMailCheckProgressItem->setStatus( msg );
-      mMailCheckProgressItem->setProgress(
-        (numBytesToRead <= 100) ? 50  // We never know what the server tells us
-        // This way of dividing is required for > 21MB of mail
-        : (numBytesRead / (numBytesToRead / 100)) );
+      if( mMailCheckProgressItem ) {
+          mMailCheckProgressItem->setStatus( msg );
+          mMailCheckProgressItem->setProgress(
+           (numBytesToRead <= 100) ? 50  // We never know what the server tells us
+           // This way of dividing is required for > 21MB of mail
+           : (numBytesRead / (numBytesToRead / 100)) );
+      }
     }
     return;
   }
