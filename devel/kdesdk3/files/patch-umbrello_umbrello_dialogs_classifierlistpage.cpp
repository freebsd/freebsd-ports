--- patch-umbrello:umbrello:dialogs:classifierlistpage.cpp begins here ---
--- umbrello/umbrello/dialogs/classifierlistpage.cpp.old	Mon Oct 25 16:09:31 2004
+++ umbrello/umbrello/dialogs/classifierlistpage.cpp	Mon Oct 25 16:09:56 2004
@@ -348,7 +348,7 @@
 	//now change around in the list
 	UMLClassifierListItem* currentAtt = getItemList().at( index );
 	takeClassifier(currentAtt);
-	addClassifier(currentAtt, index + 2);
+	addClassifier(currentAtt, index + 1);
 	slotClicked( item );
 }