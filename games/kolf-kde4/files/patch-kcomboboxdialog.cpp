--- kcomboboxdialog.cpp.orig	2018-08-29 20:31:46 UTC
+++ kcomboboxdialog.cpp
@@ -94,7 +94,7 @@ QString KComboBoxDialog::getItem( const 
 		KConfigGroup *configGroup = new KConfigGroup(config->group("Notification Messages"));
 		prevAnswer = configGroup->readEntry( dontAskAgainName,QString() );
 		if ( !prevAnswer.isEmpty() )
-			if ( _items.contains( prevAnswer ) > 0 )
+			if ( bool(_items.contains( prevAnswer ) ) )
 				return prevAnswer;
 	}
 
