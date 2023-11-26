--- src/svg/qsvghandler.cpp.orig	2023-10-02 03:05:52 UTC
+++ src/svg/qsvghandler.cpp
@@ -3606,6 +3606,8 @@ static bool detectCycles(const QSvgNode *node, QList<c
 
 static bool detectCycles(const QSvgNode *node, QList<const QSvgUse *> active = {})
 {
+    if (Q_UNLIKELY(!node))
+        return false;
     switch (node->type()) {
     case QSvgNode::DOC:
     case QSvgNode::G:
