--- src/Sync/DirtyList.cpp.orig	2022-06-11 16:32:14 UTC
+++ src/Sync/DirtyList.cpp
@@ -342,7 +342,7 @@ bool DirtyListDescriber::showChanges(QWidget* aParent)
 
 bool DirtyListDescriber::addRoad(Way* R)
 {
-    QListWidgetItem* it = new QListWidgetItem(QApplication::translate("DirtyListExecutor","ADD road %1").arg(R->id().numId) + userName(R), theListWidget);
+    QListWidgetItem* it = new QListWidgetItem(QApplication::translate("DirtyListExecutor","ADD way %1").arg(R->id().numId) + userName(R), theListWidget);
     it->setData(Qt::UserRole, QVariant::fromValue(R->id()));
     ++glbAdded;
     ++glbWaysAdded;
@@ -351,7 +351,7 @@ bool DirtyListDescriber::addRoad(Way* R)
 
 bool DirtyListDescriber::addPoint(Node* Pt)
 {
-    QListWidgetItem* it = new QListWidgetItem(QApplication::translate("DirtyListExecutor","ADD trackpoint %1").arg(Pt->id().numId) + userName(Pt), theListWidget);
+    QListWidgetItem* it = new QListWidgetItem(QApplication::translate("DirtyListExecutor","ADD node %1").arg(Pt->id().numId) + userName(Pt), theListWidget);
     it->setData(Qt::UserRole, QVariant::fromValue(Pt->id()));
     ++glbAdded;
     ++glbNodesAdded;
@@ -369,7 +369,7 @@ bool DirtyListDescriber::addRelation(Relation* R)
 
 bool DirtyListDescriber::updatePoint(Node* Pt)
 {
-    QListWidgetItem* it = new QListWidgetItem(QApplication::translate("DirtyListExecutor","UPDATE trackpoint %1").arg(Pt->id().numId) + userName(Pt), theListWidget);
+    QListWidgetItem* it = new QListWidgetItem(QApplication::translate("DirtyListExecutor","UPDATE node %1").arg(Pt->id().numId) + userName(Pt), theListWidget);
     it->setData(Qt::UserRole, QVariant::fromValue(Pt->id()));
     ++glbUpdated;
     ++glbNodesUpdated;
@@ -387,7 +387,7 @@ bool DirtyListDescriber::updateRelation(Relation* R)
 
 bool DirtyListDescriber::updateRoad(Way* R)
 {
-    QListWidgetItem* it = new QListWidgetItem(QApplication::translate("DirtyListExecutor","UPDATE road %1").arg(R->id().numId) + userName(R), theListWidget);
+    QListWidgetItem* it = new QListWidgetItem(QApplication::translate("DirtyListExecutor","UPDATE way %1").arg(R->id().numId) + userName(R), theListWidget);
     it->setData(Qt::UserRole, QVariant::fromValue(R->id()));
     ++glbUpdated;
     ++glbWaysUpdated;
@@ -396,7 +396,7 @@ bool DirtyListDescriber::updateRoad(Way* R)
 
 bool DirtyListDescriber::erasePoint(Node* Pt)
 {
-    QListWidgetItem* it = new QListWidgetItem(QApplication::translate("DirtyListExecutor","REMOVE trackpoint %1").arg(Pt->id().numId) + userName(Pt), theListWidget);
+    QListWidgetItem* it = new QListWidgetItem(QApplication::translate("DirtyListExecutor","REMOVE node %1").arg(Pt->id().numId) + userName(Pt), theListWidget);
     it->setData(Qt::UserRole, QVariant::fromValue(Pt->id()));
     ++glbDeleted;
     ++glbNodesDeleted;
@@ -405,7 +405,7 @@ bool DirtyListDescriber::erasePoint(Node* Pt)
 
 bool DirtyListDescriber::eraseRoad(Way* R)
 {
-    QListWidgetItem* it = new QListWidgetItem(QApplication::translate("DirtyListExecutor","REMOVE road %1").arg(R->id().numId) + userName(R), theListWidget);
+    QListWidgetItem* it = new QListWidgetItem(QApplication::translate("DirtyListExecutor","REMOVE way %1").arg(R->id().numId) + userName(R), theListWidget);
     it->setData(Qt::UserRole, QVariant::fromValue(R->id()));
     ++glbDeleted;
     ++glbWaysDeleted;
@@ -593,9 +593,9 @@ bool DirtyListExecutor::addRoad(Way *R)
 {
     Progress->setValue(++Done);
 
-    qDebug() << QString("ADD road %1").arg(R->id().numId);
+    qDebug() << QString("ADD way %1").arg(R->id().numId);
 
-    Progress->setLabelText(tr("ADD road %1").arg(R->id().numId) + userName(R));
+    Progress->setLabelText(tr("ADD way %1").arg(R->id().numId) + userName(R));
     QEventLoop L; L.processEvents(QEventLoop::ExcludeUserInputEvents);
 
     QString DataIn, DataOut;
@@ -627,9 +627,9 @@ bool DirtyListExecutor::addPoint(Node* Pt)
 {
     Progress->setValue(++Done);
 
-    qDebug() << QString("ADD trackpoint %1").arg(Pt->id().numId);
+    qDebug() << QString("ADD node %1").arg(Pt->id().numId);
 
-    Progress->setLabelText(tr("ADD trackpoint %1").arg(Pt->id().numId) + userName(Pt));
+    Progress->setLabelText(tr("ADD node %1").arg(Pt->id().numId) + userName(Pt));
     QEventLoop L; L.processEvents(QEventLoop::ExcludeUserInputEvents);
 
     QString DataIn, DataOut;
@@ -693,9 +693,9 @@ bool DirtyListExecutor::updateRoad(Way* R)
 {
     Progress->setValue(++Done);
 
-    qDebug() << QString("UPDATE road %1").arg(R->id().numId);
+    qDebug() << QString("UPDATE way %1").arg(R->id().numId);
 
-    Progress->setLabelText(tr("UPDATE road %1").arg(R->id().numId) + userName(R));
+    Progress->setLabelText(tr("UPDATE way %1").arg(R->id().numId) + userName(R));
     QEventLoop L; L.processEvents(QEventLoop::ExcludeUserInputEvents);
     QString URL = theDownloader->getURLToUpdate("way",stripToOSMId(R->id()));
     QString DataIn, DataOut;
@@ -724,9 +724,9 @@ bool DirtyListExecutor::updatePoint(Node* Pt)
 {
     Progress->setValue(++Done);
 
-    qDebug() << QString("UPDATE trackpoint %1").arg(Pt->id().numId);
+    qDebug() << QString("UPDATE node %1").arg(Pt->id().numId);
 
-    Progress->setLabelText(tr("UPDATE trackpoint %1").arg(Pt->id().numId) + userName(Pt));
+    Progress->setLabelText(tr("UPDATE node %1").arg(Pt->id().numId) + userName(Pt));
     QEventLoop L; L.processEvents(QEventLoop::ExcludeUserInputEvents);
 //	QString URL("/api/0.3/node/%1");
 //	URL = URL.arg(stripToOSMId(Pt->id()));
@@ -757,9 +757,9 @@ bool DirtyListExecutor::erasePoint(Node *Pt)
 {
     Progress->setValue(++Done);
 
-    qDebug() << QString("REMOVE trackpoint %1").arg(Pt->id().numId);
+    qDebug() << QString("REMOVE node %1").arg(Pt->id().numId);
 
-    Progress->setLabelText(tr("REMOVE trackpoint %1").arg(Pt->id().numId) + userName(Pt));
+    Progress->setLabelText(tr("REMOVE node %1").arg(Pt->id().numId) + userName(Pt));
     QEventLoop L; L.processEvents(QEventLoop::ExcludeUserInputEvents);
 //	QString URL("/api/0.3/node/%1");
 //	URL = URL.arg(stripToOSMId(Pt->id()));
@@ -784,9 +784,9 @@ bool DirtyListExecutor::eraseRoad(Way *R)
 {
     Progress->setValue(++Done);
 
-    qDebug() << QString("REMOVE road %1").arg(R->id().numId);
+    qDebug() << QString("REMOVE way %1").arg(R->id().numId);
 
-    Progress->setLabelText(tr("REMOVE road %1").arg(R->id().numId) + userName(R));
+    Progress->setLabelText(tr("REMOVE way %1").arg(R->id().numId) + userName(R));
     QEventLoop L; L.processEvents(QEventLoop::ExcludeUserInputEvents);
 //	QString URL("/api/0.3/way/%1");
 //	URL = URL.arg(stripToOSMId(R->id()));
