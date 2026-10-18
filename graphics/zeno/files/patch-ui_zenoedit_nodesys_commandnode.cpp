--- ui/zenoedit/nodesys/commandnode.cpp.orig	2024-09-30 13:46:54 UTC
+++ ui/zenoedit/nodesys/commandnode.cpp
@@ -72,7 +72,7 @@ void CommandNode::onExecuteClicked()
     QModelIndex commandsIdx = pModel->paramIndex(subgIdx, this->index(), "commands", true);
     ZASSERT_EXIT(commandsIdx.isValid());
     QString commands = commandsIdx.data(ROLE_PARAM_VALUE).toString();
-    QStringList cmds = commands.split("\n", QString::SkipEmptyParts);
+    QStringList cmds = commands.split("\n", Qt::SkipEmptyParts);
     for (QString cmd : cmds) {
         //api examples:
         // NewGraph("graphName")
