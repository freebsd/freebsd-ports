--- src/itemfactory.cpp.orig	Thu Mar 18 09:44:04 2004
+++ src/itemfactory.cpp	Thu Mar 18 09:44:57 2004
@@ -218,7 +218,7 @@
 		annot = name + "\n" + comment;
 
 	/* And finaly create the item */
-	Item *item = new Item( "", (nameInAnnots ? "" : name), icon,
+	Item *item = new Item( "", (nameInAnnots ? QString("") : name), icon,
 	                       false, false,/*true, true,*/ // TODO: titleForProg() and iconForProg() !!
 	                       annot, false, runC, parent );
 	parent->insertItem(item);
