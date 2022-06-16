--- src/Sync/DirtyListExecutorOSC.cpp.orig	2022-06-11 16:33:19 UTC
+++ src/Sync/DirtyListExecutorOSC.cpp
@@ -368,9 +368,9 @@ bool DirtyListExecutorOSC::addRoad(Way *F)
 {
     Progress->setValue(++Done);
 
-    qDebug() << QString("ADD road %1").arg(F->id().numId);
+    qDebug() << QString("ADD way %1").arg(F->id().numId);
 
-    Progress->setLabelText(tr("ADD road %1").arg(F->id().numId) + userName(F));
+    Progress->setLabelText(tr("ADD way %1").arg(F->id().numId) + userName(F));
     QEventLoop L; L.processEvents(QEventLoop::ExcludeUserInputEvents);
 
     OscCreate(F);
@@ -383,9 +383,9 @@ bool DirtyListExecutorOSC::addPoint(Node* F)
 {
     Progress->setValue(++Done);
 
-    qDebug() << QString("ADD trackpoint %1").arg(F->id().numId);
+    qDebug() << QString("ADD node %1").arg(F->id().numId);
 
-    Progress->setLabelText(tr("ADD trackpoint %1").arg(F->id().numId) + userName(F));
+    Progress->setLabelText(tr("ADD node %1").arg(F->id().numId) + userName(F));
     QEventLoop L; L.processEvents(QEventLoop::ExcludeUserInputEvents);
 
     OscCreate(F);
@@ -414,9 +414,9 @@ bool DirtyListExecutorOSC::updateRoad(Way* F)
 {
     Progress->setValue(++Done);
 
-    qDebug() << QString("UPDATE road %1").arg(F->id().numId);
+    qDebug() << QString("UPDATE way %1").arg(F->id().numId);
 
-    Progress->setLabelText(tr("UPDATE road %1").arg(F->id().numId) + userName(F));
+    Progress->setLabelText(tr("UPDATE way %1").arg(F->id().numId) + userName(F));
     QEventLoop L; L.processEvents(QEventLoop::ExcludeUserInputEvents);
 
     OscModify(F);
@@ -428,9 +428,9 @@ bool DirtyListExecutorOSC::updatePoint(Node* F)
 {
     Progress->setValue(++Done);
 
-    qDebug() << QString("UPDATE trackpoint %1").arg(F->id().numId);
+    qDebug() << QString("UPDATE node %1").arg(F->id().numId);
 
-    Progress->setLabelText(tr("UPDATE trackpoint %1").arg(F->id().numId) + userName(F));
+    Progress->setLabelText(tr("UPDATE node %1").arg(F->id().numId) + userName(F));
     QEventLoop L; L.processEvents(QEventLoop::ExcludeUserInputEvents);
 
     OscModify(F);
@@ -442,9 +442,9 @@ bool DirtyListExecutorOSC::erasePoint(Node *F)
 {
     Progress->setValue(++Done);
 
-    qDebug() << QString("REMOVE trackpoint %1").arg(F->id().numId);
+    qDebug() << QString("REMOVE node %1").arg(F->id().numId);
 
-    Progress->setLabelText(tr("REMOVE trackpoint %1").arg(F->id().numId) + userName(F));
+    Progress->setLabelText(tr("REMOVE node %1").arg(F->id().numId) + userName(F));
     QEventLoop L; L.processEvents(QEventLoop::ExcludeUserInputEvents);
 
     OscDelete(F);
@@ -456,9 +456,9 @@ bool DirtyListExecutorOSC::eraseRoad(Way *F)
 {
     Progress->setValue(++Done);
 
-    qDebug() << QString("REMOVE road %1").arg(F->id().numId);
+    qDebug() << QString("REMOVE way %1").arg(F->id().numId);
 
-    Progress->setLabelText(tr("REMOVE road %1").arg(F->id().numId) + userName(F));
+    Progress->setLabelText(tr("REMOVE way %1").arg(F->id().numId) + userName(F));
     QEventLoop L; L.processEvents(QEventLoop::ExcludeUserInputEvents);
 
     OscDelete(F);
