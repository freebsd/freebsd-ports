--- kmailcvt/filter_oe.cxx	Mon May 23 14:12:15 2005
+++ kmailcvt/filter_oe.cxx	Tue Jun 21 14:50:03 2005
@@ -389,20 +389,20 @@
 {
     bool found = false;
     bool foundFilename = false;
-    QString folder = "";
+    QString folder;
     // we must do this because folder with more than one upper letter
     // at start have maybe not a file named like the folder !!!
     QString search = filename.lower();
     
     while (!found)
     {
-        for ( QValueList<QString[4]>::Iterator it = folderStructure.begin(); it != folderStructure.end(); it++) {
-            QString tmp[4] = *it;
+        for ( FolderStructureIterator it = folderStructure.begin(); it != folderStructure.end(); it++) {
+            FolderStructure tmp = *it;
             if(foundFilename == false) {
                 QString _tmpFileName = tmp[1];
                 _tmpFileName = _tmpFileName.lower();
                 if(_tmpFileName == search) {
-                    folder.prepend( "-" + tmp[0]);
+                    folder.prepend( tmp[0] + QString::fromLatin1("-") );
                     search = tmp[3];
                     foundFilename = true;
                 }
@@ -410,18 +410,18 @@
                 QString _currentID = tmp[2];
                 QString _parentID = tmp[3];
                 if(_currentID == search) {
-                    if(_parentID == "") { // this is the root of the folder
+                    if(_parentID.isEmpty()) { // this is the root of the folder
                         found = true;
                         break;
                     } else {
-                        folder.prepend( "-" + tmp[0]);
+                        folder.prepend( tmp[0] + QString::fromLatin1("-") );
                         search = tmp[3];
                     }
                 }
             }
         }
         // need to break the while loop maybe in some cases
-        if((foundFilename == false) && (folder == "")) return folder;
+        if((foundFilename == false) && (folder.isEmpty())) return folder;
     }
     return folder;
 }
