--- ui/zenoui/nodesys/nodesys_common.h.orig	2024-09-30 13:46:54 UTC
+++ ui/zenoui/nodesys/nodesys_common.h
@@ -38,7 +38,7 @@ struct SEARCH_RECORD {
     QPointF pos;
 };
 
-struct NODES_MIME_DATA : public QObjectUserData
+struct NODES_MIME_DATA
 {
     QModelIndexList nodes;
     QPersistentModelIndex m_fromSubg;
