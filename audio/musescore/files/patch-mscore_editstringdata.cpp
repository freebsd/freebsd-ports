--- mscore/editstringdata.cpp.orig	2018-12-11 15:55:46 UTC
+++ mscore/editstringdata.cpp
@@ -52,7 +52,8 @@ EditStringData::EditStringData(QWidget *parent, QList<
                   strg = (*_strings)[numOfStrings - i - 1];
                   _stringsLoc.append(strg);
                   QTableWidgetItem *newCheck = new QTableWidgetItem();
-                  newCheck->setFlags(Qt::ItemFlag(Qt::ItemIsUserCheckable | Qt::ItemIsEnabled));
+                  Qt::ItemFlags flags(Qt::ItemIsUserCheckable | Qt::ItemIsEnabled);
+                  newCheck->setFlags(flags);
                   newCheck->setCheckState(strg.open ? Qt::Checked : Qt::Unchecked);
                   stringList->setItem(i, 0, newCheck);
                   QTableWidgetItem *newPitch = new QTableWidgetItem(midiCodeToStr(strg.pitch));
@@ -168,7 +169,8 @@ void EditStringData::newStringClicked()
             _stringsLoc.insert(i, strg);
             stringList->insertRow(i);
             QTableWidgetItem *newCheck = new QTableWidgetItem();
-            newCheck->setFlags(Qt::ItemFlag(Qt::ItemIsUserCheckable | Qt::ItemIsEnabled));
+            Qt::ItemFlags flags(Qt::ItemIsUserCheckable | Qt::ItemIsEnabled);
+            newCheck->setFlags(flags);
             newCheck->setCheckState(strg.open ? Qt::Checked : Qt::Unchecked);
             stringList->setItem(i, 0, newCheck);
             QTableWidgetItem *newPitch = new QTableWidgetItem(midiCodeToStr(strg.pitch));
