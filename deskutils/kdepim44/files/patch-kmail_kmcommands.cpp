--- ../kmail/kmcommands.cpp	2009/02/16 19:10:32	927080
+++ ../kmail/kmcommands.cpp	2009/02/16 19:12:30	927081
@@ -2320,8 +2320,10 @@
           mUrl.pathOrUrl() ), QString(), KGuiItem(i18n("Execute")), KStandardGuiItem::cancel() ) != KMessageBox::Yes)
         return Canceled;
     }
-    if ( !KMail::Util::handleUrlOnMac( mUrl.pathOrUrl() ) )
-      (void) new KRun( mUrl, mMainWidget );
+    if ( !KMail::Util::handleUrlOnMac( mUrl.pathOrUrl() ) ) {
+      KRun *runner = new KRun( mUrl, mMainWidget ); // will delete itself
+      runner->setRunExecutables( false );
+    }
   }
   else
     return Failed;
