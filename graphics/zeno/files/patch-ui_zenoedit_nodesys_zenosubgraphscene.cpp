--- ui/zenoedit/nodesys/zenosubgraphscene.cpp.orig	2024-09-30 13:46:54 UTC
+++ ui/zenoedit/nodesys/zenosubgraphscene.cpp
@@ -946,7 +946,7 @@ void ZenoSubGraphScene::mouseMoveEvent(Q
 
 void ZenoSubGraphScene::mouseReleaseEvent(QGraphicsSceneMouseEvent* event)
 {
-    if (m_tempLink && event->button() != Qt::MidButton && event->button() != Qt::RightButton)
+    if (m_tempLink && event->button() != Qt::MiddleButton && event->button() != Qt::RightButton)
     {
         onTempLinkClosed();
         removeItem(m_tempLink);
@@ -1119,7 +1119,7 @@ void ZenoSubGraphScene::updateKeyFrame()
     for (const QModelIndex &index : selectNodesIndice()) {
         keys << index.data(ROLE_KEYFRAMES).value<QVector<int>>();
     }
-    qSort(keys.begin(), keys.end());
+    std::sort(keys.begin(), keys.end());
     keys.erase(std::unique(keys.begin(), keys.end()), keys.end());
     zenoApp->getMainWindow()->timeline()->updateKeyFrames(keys);
 }
